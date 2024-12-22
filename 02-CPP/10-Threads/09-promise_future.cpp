#include <iostream>
#include <future>
#include <thread>
#include <chrono>

// Function to perform a time-consuming calculation
int longCalculation(int a, int b) 
{
    // Simulate a time-consuming operation
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return a + b;
}

int main() 
{
    // Create a promise
    std::promise<int> resultPromise;

    // Get the future from the promise
    std::future<int> resultFuture = resultPromise.get_future();

    // Launch a new thread to perform the calculation
    std::thread calculationThread([&resultPromise]() {
        int result = longCalculation(20, 22);
        resultPromise.set_value(result);
    });

    // Do some other work in the main thread
    std::cout << "Waiting for the result..." << std::endl;

    // Wait for the result and retrieve it
    int result = resultFuture.get();

    std::cout << "Result: " << result << std::endl;

    // Join the thread
    calculationThread.join();

    return 0;
}