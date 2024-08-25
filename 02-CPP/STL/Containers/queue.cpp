#include <iostream>
#include <queue>

int main() {
    // Create a queue of integers
    std::queue<int> q;

    // Push elements into the queue
    q.push(10);
    q.push(20);
    q.push(30);

    // Display the front and back elements of the queue
    std::cout << "Front element: " << q.front() << std::endl; // Output: 10
    std::cout << "Back element: " << q.back() << std::endl;   // Output: 30

    // Pop an element from the queue
    q.pop();

    // Display the front and back elements after popping
    std::cout << "Front element after pop: " << q.front() << std::endl; // Output: 20
    std::cout << "Back element after pop: " << q.back() << std::endl;   // Output: 30

    // Check the size of the queue
    std::cout << "Size of the queue: " << q.size() << std::endl; // Output: 2

    // Check if the queue is empty
    if (q.empty()) {
        std::cout << "The queue is empty." << std::endl;
    } else {
        std::cout << "The queue is not empty." << std::endl; // Output: The queue is not empty.
    }

    // Clear all elements from the queue
    while (!q.empty()) {
        q.pop();
    }

    std::cout << "Size of the queue after clearing: " << q.size() << std::endl; // Output: 0

    return 0;
}
