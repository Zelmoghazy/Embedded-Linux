#include <iostream>
#include <thread>

void task1() {
    std::cout << "Task 1 is starting...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Task 1 is finished.\n";
}

int main() {
    std::thread t1(task1); // Create a thread executing task1

    std::cout << "Waiting for Task 1 to complete...\n";
    t1.join(); // Main thread waits for t1 to finish

    std::cout << "Task 1 has completed. Now exiting main.\n";
    return 0;
}
