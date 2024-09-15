#include <iostream>
#include <set>

int main() {
    // Declare a multiset of integers
    std::multiset<int> numbers;

    // Insert elements into the multiset
    numbers.insert(10);
    numbers.insert(20);
    numbers.insert(10);  // Duplicate value
    numbers.insert(30);
    numbers.insert(20);  // Duplicate value
    numbers.insert(40);

    // Display elements of the multiset
    std::cout << "Multiset elements: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Count the occurrences of an element
    int count_10 = numbers.count(10);
    std::cout << "Number 10 occurs " << count_10 << " times." << std::endl;

    // Find an element in the multiset
    auto it = numbers.find(20);
    if (it != numbers.end()) {
        std::cout << "Element " << *it << " found in the multiset." << std::endl;
    }

    // Erase an element (removes all occurrences of the element)
    numbers.erase(20);
    std::cout << "After erasing 20, multiset elements: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Insert duplicate elements
    numbers.insert(30);
    numbers.insert(30);

    // Display elements after inserting duplicates
    std::cout << "After inserting duplicates, multiset elements: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Get the lower and upper bounds for a value
    auto lower = numbers.lower_bound(30);
    auto upper = numbers.upper_bound(30);

    std::cout << "Lower bound of 30: " << *lower << std::endl;
    std::cout << "Upper bound of 30: " << *upper << std::endl;

    return 0;
}
