#include <functional>
#include <iostream>
#include <set>

int main() {
    // Create a set of integers
    std::set<int, std::greater<>> mySet;

    // Insert elements into the set
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    mySet.insert(40);
    mySet.insert(50);

    // Attempting to insert duplicate elements (will not be added)
    mySet.insert(20);
    mySet.insert(40);


    // Display the elements of the set
    std::cout << "Elements in the set: ";
    for (int elem : mySet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Check if an element exists in the set using contains (C++20 and later)
    /* 
    int key = 30;
    if (mySet.contains(key)) {
        std::cout << key << " is in the set." << std::endl;
    } else {
        std::cout << key << " is not in the set." << std::endl;
    } 
    */
    
    // Check if an element exists in the set
    int key = 30;
    if (mySet.find(key) != mySet.end()) {
        std::cout << key << " is in the set." << std::endl;
    } else {
        std::cout << key << " is not in the set." << std::endl;
    }

    // Erase an element from the set
    mySet.erase(30);
    std::cout << "After erasing 30, elements in the set: ";
    for (int elem : mySet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Iterate and display elements in reverse order
    std::cout << "Elements in reverse order: ";
    for (auto rit = mySet.rbegin(); rit != mySet.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // Size of the set
    std::cout << "Size of the set: " << mySet.size() << std::endl;

    return 0;
}
