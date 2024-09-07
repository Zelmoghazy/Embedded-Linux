#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>
#include <random>

/*
    - Multithreading : is the ability of a program to execute multiple instructions at the same time
        - concurrency : threads interact to solve a problem
        - parallelism : threads do not interact 

    - Multitasking : performing multiple tasks or processes over a certain period of time by executing them concurrently
        - on a single processor system multitasking is implemented by time slicing an the CPU switches between different tasks

    ----------------------------------------------------------------------------------

    - Thread : work which can be scheduled to execute on one core
        - a thread is contained inside a process, share process resources
          and each thread has its own call stack

    - Process : used to start a seperate program

    - Resource : memory, file handle, non-thread-safe objects

    - Race condition : occurs when a resource is accessed by multiple thread simultaneously and at least one access is write

    Problems for which multithreading is the answer
        - tasks which can intuitively be split into independent processing steps
        - a problem where each step has a clear input and output
        - intensive computations
        - continuous access to a large read-only data set
        - processing a stream of large data files

    Problems for which multithreading is the only answer
        - tasks whose performance would be unacceptable as a single thread
        - processes where the workload cannot be anticipated
        - manage concurrent access to multiple resources, such as an operating system
        - external clients sending requests to a process in a random and unpredictable fashion, such as PostgreSQL
 */



// Shared data structure
struct SharedData 
{
    std::queue<int> buffer;
    const size_t maxSize = 10;
    std::mutex mutex;
    std::condition_variable not_full;
    std::condition_variable not_empty;
    bool done = false;
};

// Producer function
void producer(SharedData& data, int id) 
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < 20; ++i) 
    {
        // generate a random number
        int value = dis(gen);
        {
            // protect shared resource using a mutex
            std::unique_lock<std::mutex> lock(data.mutex);
            
            // wait when the buffer is full
            data.not_full.wait(lock, [&]() { return data.buffer.size() < data.maxSize || data.done; });
            if (data.done) break;
            
            // add values to the queue
            data.buffer.push(value);
            std::cout << "Producer " << id << " produced: " << value << std::endl;
        }
        data.not_empty.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "Producer " << id << " finished" << std::endl;
}

// Consumer function
void consumer(SharedData& data, int id) 
{
    while (true) {
        int value;
        {
            // protect shared resource using a mutex
            std::unique_lock<std::mutex> lock(data.mutex);

            // wait when the buffer is empty.
            data.not_empty.wait(lock, [&]() { return !data.buffer.empty() || data.done; });
            if (data.buffer.empty() && data.done) break;
            
            // consume values from the queue
            value = data.buffer.front();
            data.buffer.pop();
            std::cout << "Consumer " << id << " consumed: " << value << std::endl;
        }
        data.not_full.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    std::cout << "Consumer " << id << " finished" << std::endl;
}

int main() {
    SharedData shared_data;
    
    // Create producer threads
    std::thread producer1(producer, std::ref(shared_data), 1);
    std::thread producer2(producer, std::ref(shared_data), 2);

    // Create consumer threads
    std::thread consumer1(consumer, std::ref(shared_data), 1);
    std::thread consumer2(consumer, std::ref(shared_data), 2);

    // Wait for producers to finish
    producer1.join();
    producer2.join();

    // Signal consumers to finish
    {
        std::lock_guard<std::mutex> lock(shared_data.mutex);
        shared_data.done = true;
    }
    shared_data.not_empty.notify_all();

    // Wait for consumers to finish
    consumer1.join();
    consumer2.join();

    std::cout << "All threads have finished." << std::endl;
    return 0;
}