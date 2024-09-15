#include <iostream>
#include <unordered_set>

int main() {
    // Create an unordered_multiset of integers
    std::unordered_multiset<int> myMultiSet;

    // Inserting elements
    myMultiSet.insert(10);
    myMultiSet.insert(20);
    myMultiSet.insert(30);
    myMultiSet.insert(40);

    // Inserting duplicate elements
    myMultiSet.insert(20);
    myMultiSet.insert(30);

    // Displaying the elements
    std::cout << "Elements in myMultiSet: ";
    for (const int& elem : myMultiSet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Count occurrences of a specific element
    int search = 20;
    std::cout << search << " appears " << myMultiSet.count(search) << " times in the set." << std::endl;

    // Erasing all occurrences of an element
    myMultiSet.erase(20);

    // Check the occurrences of an element after erasing
    std::cout << search << " appears " << myMultiSet.count(search) << " times in the set after erasure." << std::endl;

    // Displaying the elements after erasure
    std::cout << "Elements in myMultiSet after erasure: ";
    for (const int& elem : myMultiSet) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Get the size of the multiset
    std::cout << "Size of myMultiSet: " << myMultiSet.size() << std::endl;

    // Clear all elements from the multiset
    myMultiSet.clear();
    std::cout << "Size of myMultiSet after clearing: " << myMultiSet.size() << std::endl;

    return 0;
}
