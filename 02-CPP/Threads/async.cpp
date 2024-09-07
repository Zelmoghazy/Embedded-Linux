#include <iostream>
#include <future>
#include <chrono>
#include <thread>

// A simple function that simulates a long-running task
int long_computation(int x) {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate work
    return x * x;
}

int main() {
    // Launch the task asynchronously and get a future to retrieve the result
    std::future<int> result = std::async(std::launch::async, long_computation, 10);

    // Do some other work while the async task is running
    std::cout << "Main thread is doing some work...\n";

    // Get the result from the asynchronous task (this will block until the task finishes)
    std::cout << "Result of long computation: " << result.get() << "\n";

    return 0;
}
