#include <iostream>
#include <thread>
#include <future>
#include <chrono>

// A simple function to be used with packaged_task
int long_computation(int x) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate a long computation
    return x * x;
}

int main() {
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
