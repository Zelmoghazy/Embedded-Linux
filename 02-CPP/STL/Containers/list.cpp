#include <iostream>
#include <list>
#include <algorithm>

int main() {
    // Create a list of integers
    std::list<int> myList;

    // Adding elements to the list
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_front(5);  // Add to the front of the list

    // Display the elements of the list
    std::cout << "Elements in the list: ";
    for (int element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Insert an element after the first element
    auto it = myList.begin();
    std::advance(it, 1);
    myList.insert(it, 15);

    // Display the elements of the list after insertion
    std::cout << "List after insertion: ";
    for (int element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Remove an element by value
    myList.remove(20);

    // Display the elements of the list after removal
    std::cout << "List after removal of 20: ";
    for (int element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Sort the list in ascending order
    myList.sort();

    // Display the sorted list
    std::cout << "Sorted list: ";
    for (int element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Reverse the list
    myList.reverse();

    // Display the reversed list
    std::cout << "Reversed list: ";
    for (int element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Find an element in the list
    it = std::find(myList.begin(), myList.end(), 15);
    if (it != myList.end()) {
        std::cout << "Element 15 found in the list." << std::endl;
    } else {
        std::cout << "Element 15 not found in the list." << std::endl;
    }

    // Erase an element by iterator
    myList.erase(it);

    // Display the list after erasing an element
    std::cout << "List after erasing 15: ";
    for (int element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
