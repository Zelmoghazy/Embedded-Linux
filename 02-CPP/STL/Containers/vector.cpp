#include <iostream>
#include <vector>
#include <algorithm> // For sort, reverse, find, etc.
#include <numeric>   // For accumulate
#include <functional>// For greater

int main(void) 
{
    // 1. Initialize vectors
    std::vector<int> vec1; // Empty vector
    std::vector<int> vec2(5, 10); // Vector of size 5, all elements are 10
    std::vector<int> vec3 = {1, 2, 3, 4, 5}; // Initializer list
    std::vector<int> vec4(vec3); // Copy constructor

    // 2. Accessing elements
    std::cout << "First element of vec3: " << vec3[0] << std::endl;
    std::cout << "Second element of vec3: " << vec3.at(1) << std::endl;

    // 3. Modifying elements
    vec3[0] = 10; // Change first element
    vec3.at(1) = 20; // Change second element

    // 4. Iterating over a vector
    std::cout << "vec3 elements: ";
    for (int i = 0; i < vec3.size(); ++i) {
        std::cout << vec3[i] << " ";
    }
    std::cout << std::endl;

    // 5. Using range-based for loop
    std::cout << "vec3 elements using range-based loop: ";
    for (int elem : vec3) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // 6. Using iterators
    std::cout << "vec3 elements using iterators: ";
    for (auto it = vec3.begin(); it != vec3.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // 7. Adding elements
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);

    // 8. Removing elements
    vec1.pop_back(); // Removes the last element

    // 9. Inserting elements
    vec1.insert(vec1.begin(), 0); // Insert 0 at the beginning
    vec1.insert(vec1.begin() + 2, 5); // Insert 5 at index 2

    // 10. Erasing elements
    vec1.erase(vec1.begin()); // Erase first element
    vec1.erase(vec1.begin(), vec1.begin() + 2); // Erase first two elements

    // 11. Capacity functions
    std::cout << "Size of vec1: " << vec1.size() << std::endl;
    std::cout << "Capacity of vec1: " << vec1.capacity() << std::endl;
    vec1.shrink_to_fit(); // Reduce capacity to fit the size
    std::cout << "Capacity after shrink_to_fit: " << vec1.capacity() << std::endl;

    // 12. Resizing a vector
    vec2.resize(10, 99); // Resizes vec2 to 10 elements, new elements initialized to 99
    std::cout << "vec2 after resizing: ";
    for (int elem : vec2) std::cout << elem << " ";
    std::cout << std::endl;

    // 13. Clearing a vector
    vec2.clear(); // Removes all elements from vec2

    // 14. Sorting a vector
    std::vector<int> vec5 = {4, 2, 3, 1, 5};
    std::sort(vec5.begin(), vec5.end()); // Sort in ascending order
    std::cout << "vec5 sorted: ";
    for (int elem : vec5) std::cout << elem << " ";
    std::cout << std::endl;

    // Sort in descending order
    std::sort(vec5.begin(), vec5.end(), std::greater<int>());
    std::cout << "vec5 sorted in descending order: ";
    for (int elem : vec5) std::cout << elem << " ";
    std::cout << std::endl;

    // 15. Reversing a vector
    std::reverse(vec5.begin(), vec5.end());
    std::cout << "vec5 reversed: ";
    for (int elem : vec5) std::cout << elem << " ";
    std::cout << std::endl;

    // 16. Finding an element
    auto it = std::find(vec5.begin(), vec5.end(), 3);
    if (it != vec5.end()) {
        std::cout << "Element 3 found at index: " << it - vec5.begin() << std::endl;
    } else {
        std::cout << "Element 3 not found" << std::endl;
    }

    // 17. Accumulate elements
    int sum = std::accumulate(vec5.begin(), vec5.end(), 0);
    std::cout << "Sum of vec5 elements: " << sum << std::endl;

    // 18. Check if vector is empty
    if (vec2.empty()) {
        std::cout << "vec2 is empty" << std::endl;
    }

    // 19. Swap two vectors
    std::cout << "Before swap, vec3: ";
    for (int elem : vec3) std::cout << elem << " ";
    std::cout << std::endl;
    std::cout << "Before swap, vec4: ";
    for (int elem : vec4) std::cout << elem << " ";
    std::cout << std::endl;

    vec3.swap(vec4);

    std::cout << "After swap, vec3: ";
    for (int elem : vec3) std::cout << elem << " ";
    std::cout << std::endl;
    std::cout << "After swap, vec4: ";
    for (int elem : vec4) std::cout << elem << " ";
    std::cout << std::endl;

    // 20. Emplace vs. Push_back
    vec3.emplace(vec3.begin(), 100); // Inserts 100 at the beginning
    vec3.push_back(200); // Adds 200 at the end
    std::cout << "vec3 after emplace and push_back: ";
    for (int elem : vec3) std::cout << elem << " ";
    std::cout << std::endl;

    // 21. Using 2D vectors
    std::vector<std::vector<int>> vec2D(3, std::vector<int>(4, 0)); // 3x4 2D vector, all elements initialized to 0
    vec2D[1][2] = 5; // Set the element at row 1, column 2 to 5

    std::cout << "2D vector elements:" << std::endl;
    for (const auto& row : vec2D) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    // 22. Vector of pairs
    std::vector<std::pair<int, std::string>> vecPairs;
    vecPairs.emplace_back(1, "one");
    vecPairs.emplace_back(2, "two");

    std::cout << "Vector of pairs:" << std::endl;
    for (const auto& p : vecPairs) {
        std::cout << p.first << " - " << p.second << std::endl;
    }

    return 0;
}
