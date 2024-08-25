#include <iostream>
#include <forward_list>
#include <algorithm>

int main() {
    // Create a forward_list of integers
    std::forward_list<int> myList;

    // Adding elements to the front of the forward_list
    myList.push_front(30);
    myList.push_front(20);
    myList.push_front(10);
    myList.push_front(5);  // Add to the front of the list

    // Display the elements of the forward_list
    std::cout << "Elements in the forward_list: ";
    for (int element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Insert an element after the first element
    auto it = myList.begin();
    myList.insert_after(it, 15);

    // Display the elements of the forward_list after insertion
    std::cout << "forward_list after insertion: ";
    for (int element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Remove an element by value
    myList.remove(20);

    // Display the elements of the forward_list after removal
    std::cout << "forward_list after removal of 20: ";
    for (int element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Sort the forward_list in ascending order
    myList.sort();

    // Display the sorted forward_list
    std::cout << "Sorted forward_list: ";
    for (int element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Reverse the forward_list
    myList.reverse();

    // Display the reversed forward_list
    std::cout << "Reversed forward_list: ";
    for (int element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Find an element in the forward_list
    it = std::find(myList.begin(), myList.end(), 15);
    if (it != myList.end()) {
        std::cout << "Element 15 found in the forward_list." << std::endl;
    } else {
        std::cout << "Element 15 not found in the forward_list." << std::endl;
    }

    // Erase an element after the first element
    myList.erase_after(myList.begin());

    // Display the forward_list after erasing an element
    std::cout << "forward_list after erasing the second element: ";
    for (int element : myList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
