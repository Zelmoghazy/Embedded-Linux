#include <iostream>
#include <deque>

int main() {
    // 1. Create a deque of integers
    std::deque<int> dq;

    // 2. Add elements to the front and back
    dq.push_back(10);  // deque: 10
    dq.push_front(5);  // deque: 5, 10
    dq.push_back(15);  // deque: 5, 10, 15

    // 3. Access elements
    std::cout << "Front element: " << dq.front() << std::endl; // Output: 5
    std::cout << "Back element: " << dq.back() << std::endl;   // Output: 15
    std::cout << "Element at index 1: " << dq[1] << std::endl; // Output: 10

    // 4. Modify elements
    dq[1] = 20;  // deque: 5, 20, 15
    std::cout << "Modified element at index 1: " << dq[1] << std::endl; // Output: 20

    // 5. Iterate through the deque
    std::cout << "Elements in deque: ";
    for (const int &element : dq) {
        std::cout << element << " "; // Output: 5 20 15
    }
    std::cout << std::endl;

    // 6. Remove elements from front and back
    dq.pop_front(); // deque: 20, 15
    dq.pop_back();  // deque: 20

    std::cout << "Deque after popping front and back: ";
    for (const int &element : dq) {
        std::cout << element << " "; // Output: 20
    }
    std::cout << std::endl;

    // 7. Insert elements at a specific position
    dq.insert(dq.begin(), 30);    // deque: 30, 20
    dq.insert(dq.end(), 40);      // deque: 30, 20, 40
    dq.insert(dq.begin() + 1, 25); // deque: 30, 25, 20, 40

    std::cout << "Deque after insertions: ";
    for (const int &element : dq) {
        std::cout << element << " "; // Output: 30 25 20 40
    }
    std::cout << std::endl;

    // 8. Erase elements
    dq.erase(dq.begin() + 1); // Removes element at index 1; deque: 30, 20, 40

    std::cout << "Deque after erasing element at index 1: ";
    for (const int &element : dq) {
        std::cout << element << " "; // Output: 30 20 40
    }
    std::cout << std::endl;

    // 9. Check size and clear the deque
    std::cout << "Size of deque: " << dq.size() << std::endl; // Output: 3
    dq.clear(); // Clear all elements

    std::cout << "Size after clearing deque: " << dq.size() << std::endl; // Output: 0

    return 0;
}
