#include <iostream>
#include <thread>
#include <future>
#include <chrono>



/*
    In C++, `std::packaged_task` is a wrapper that encapsulates a function or callable,
    allowing it to run asynchronously and provide its result through a `std::future`.

    The motivation for `std::packaged_task` is to decouple task execution from result retrieval,
    enabling asynchronous or deferred execution where the output can be accessed later.

    This is particularly useful when managing complex workflows that require results from 
    tasks executed on separate threads, as it allows error handling and result access to 
    be synchronized across threads.

    Unlike `std::async`, `std::packaged_task` offers fine-grained control over when and where
    the task is executed, making it ideal for custom threading models where you need to 
    schedule and control the lifecycle of tasks independently.
 */

// A simple function to be used with packaged_task
int long_computation(int x) 
{
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate a long computation
    return x * x;
}

int main(void) 
{
    // Create a packaged_task that wraps the function
    std::packaged_task<int(int)> task(long_computation);

    // Get the future from the task to retrieve the result later
    std::future<int> result = task.get_future();

    // Create a thread that executes the packaged_task
    std::thread t(std::move(task), 5); // Passing 5 as the argument to long_computation

    // Do some other work while the thread is running
    std::cout << "Main thread is doing some work...\n";

    // Wait for the result from the packaged_task
    std::cout << "Result of long computation: " << result.get() << "\n";

    // Join the thread
    t.join();

    return 0;
}
