#include <iostream>
#include <thread>
#include <chrono>

void sleepForExample() 
{
    std::cout << "Task 1: Sleeping for 2 seconds...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Task 1: Woke up after 2 seconds.\n";
}

void sleepUntilExample() 
{
    auto now = std::chrono::system_clock::now();
    auto wake_up_time = now + std::chrono::seconds(3);

    std::cout << "Task 2: Sleeping until a specific time (3 seconds from now)...\n";
    std::this_thread::sleep_until(wake_up_time);
    std::cout << "Task 2: Woke up at the specified time.\n";
}

void yieldExample() 
{
    for (int i = 0; i < 5; ++i) {
        std::cout << "Task 3: Yielding execution...\n";
        std::this_thread::yield(); // Yield to allow other threads to run
        std::cout << "Task 3: Resumed after yielding.\n";
    }
}

void steadyClockSleepUntilExample() 
{
    auto start = std::chrono::steady_clock::now();
    auto wake_up_time = start + std::chrono::seconds(4);

    std::cout << "Task 4: Sleeping until a steady clock time (4 seconds from start)...\n";
    std::this_thread::sleep_until(wake_up_time);
    std::cout << "Task 4: Woke up after 4 seconds using steady clock.\n";
}

int main(void) 
{
    // Launch each task in its own thread
    std::thread t1(sleepForExample);
    std::thread t2(sleepUntilExample);
    std::thread t3(yieldExample);
    std::thread t4(steadyClockSleepUntilExample);

    // Wait for all threads to complete
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << "All tasks completed.\n";

    return 0;
}
