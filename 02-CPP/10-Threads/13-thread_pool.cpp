#include <condition_variable>
#include <functional>
#include <queue>
#include <string.h>
#include <thread>
#include <vector>

class ThreadPool {
public:
    ThreadPool();
    ~ThreadPool();
    void QueueJob(const std::function<void()>& job);
    bool busy();

private:
    void ThreadLoop();

    bool should_terminate = false;           // Tells threads to stop looking for jobs
    std::mutex queue_mutex;                  // Prevents data races to the job queue
    std::condition_variable mutex_condition; // Allows threads to wait on new jobs or termination 
    std::vector<std::thread> threads;
    std::queue<std::function<void()>> jobs;
};


ThreadPool::ThreadPool() 
{
    const uint32_t num_threads = std::thread::hardware_concurrency(); 
    for (uint32_t ii = 0; ii < num_threads; ++ii) {
        threads.emplace_back(std::thread(&ThreadPool::ThreadLoop,this));
    }
}

ThreadPool::~ThreadPool() 
{
    std::unique_lock<std::mutex> lock(queue_mutex);

    should_terminate = true;

    lock.unlock();

    mutex_condition.notify_all();
    for (std::thread& active_thread : threads) {
        active_thread.join();
    }
    threads.clear();
}


void ThreadPool::ThreadLoop() 
{
    while (true) 
    {
        std::function<void()> job;
        
        std::unique_lock<std::mutex> lock(queue_mutex);

        mutex_condition.wait(lock, [this] {
            return (!jobs.empty() || should_terminate);
        });

        if (should_terminate) {
            return;
        }

        job = jobs.front();     // get task from task list
        jobs.pop();             // remove the task from the list because we are going to execute it

        lock.unlock();

        job();                 // Execute the task
    }
}

void ThreadPool::QueueJob(const std::function<void()>& job) 
{
    std::unique_lock<std::mutex> lock(queue_mutex);

    jobs.push(job);
    
    lock.unlock();

    mutex_condition.notify_one();
}

bool ThreadPool::busy() 
{
    bool poolbusy;
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        poolbusy = !jobs.empty();
    }
    return poolbusy;
}
