#include <iostream>
#include <thread>

void task2() {
    std::cout << "Task 2 is starting...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Task 2 is finished.\n";
}

int main() {
    std::thread t2(task2); // Create a thread executing task2

    std::cout << "Detaching Task 2...\n";
    t2.detach(); // t2 will run independently

    std::cout << "Main thread is exiting. Task 2 may still be running...\n";
    return 0;
}
