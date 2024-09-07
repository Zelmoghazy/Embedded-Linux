#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;

// shared variable
bool ready = false;

void print_id(int id) 
{
    std::unique_lock<std::mutex> lock(mtx);
    while (!ready) {
        // condition variables can be used to synchronize multiple threads,
        // making them wait until a particular condition is met before proceeding.
        cv.wait(lock);
    }
    std::cout << "Thread " << id << " is running." << std::endl;
}

void go() 
{
    std::unique_lock<std::mutex> lock(mtx);
    ready = true;
    // notify all threads
    cv.notify_all();
}

int main(void) 
{
    // create 5 threads
    std::thread threads[5];
    for (int i = 0; i < 5; ++i) {
        threads[i] = std::thread(print_id, i);
    }
    
    std::cout << "5 threads ready to race..." << std::endl;

    // signal all threads to start 
    go();

    for (auto& th : threads) {
        th.join();
    }

    return 0;
}