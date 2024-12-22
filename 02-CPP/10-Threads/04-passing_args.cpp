#include <iostream>
#include <thread>

// Function to be executed by the thread
void printMessage(int x, const std::string& message) 
{
    std::cout << "Message: " << message << ", Number: " << x << std::endl;
}

int main(void) 
{
    int num = 42;
    std::string text = "Hello from the thread!";

    // Create a thread using a lambda function
    std::thread t1([num, text]() {
        printMessage(num, text);
    });

    // or
    std::thread t2(printMessage, num, text);

    // Wait for the thread to finish
    t1.join();
    t2.join();

    return 0;
}
