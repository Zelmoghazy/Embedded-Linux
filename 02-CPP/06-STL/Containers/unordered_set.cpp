#include <iostream>
#include <unordered_set>

int main() {
    // Create an unordered_set of integers
    std::unordered_set<int> mySet;

    // Inserting elements
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    mySet.insert(40);

    // Attempting to insert a duplicate (won't be added)
    mySet.insert(20);

    auto result = mySet.insert(10);
    if (result.second) {
        std::cout << "Inserted 10 successfully.\n";
    } else {
        std::cout << "10 is a duplicate.\n";
    }

    // Displaying the elements
    std::cout << "Elements in mySet: ";
    for (const int& elem : mySet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Check if an element exists
    int search = 20;
    if (mySet.find(search) != mySet.end()) {
        std::cout << search << " is found in the set." << std::endl;
    } else {
        std::cout << search << " is not found in the set." << std::endl;
    }

    // Erasing an element
    mySet.erase(20);

    // Check if an element exists after erasing
    if (mySet.find(search) != mySet.end()) {
        std::cout << search << " is still in the set." << std::endl;
    } else {
        std::cout << search << " has been removed from the set." << std::endl;
    }

    // Displaying the elements after erasure
    std::cout << "Elements in mySet after erasure: ";
    for (const int& elem : mySet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Get the size of the set
    std::cout << "Size of mySet: " << mySet.size() << std::endl;

    // Clear all elements from the set
    mySet.clear();
    std::cout << "Size of mySet after clearing: " << mySet.size() << std::endl;

    return 0;
}
