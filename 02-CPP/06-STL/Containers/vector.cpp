#include <iostream>
#include <vector>
#include <algorithm> // For sort, reverse, find, etc.
#include <numeric>   // For accumulate
#include <functional>// For greater

void printVector(const std::vector<int>& vec, const char *message) {
    std::cout << message << " ";
    for (int elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

/* 
    vector and array are the only standard containers that offer the following advantages:
        - the fastest general-purpose access (random access, including being vectorization-friendly);
        - the fastest default access pattern (begin-to-end or end-to-begin is prefetcher-friendly);
        - the lowest space overhead (contiguous layout has zero per-element overhead, which is cache-friendly).
 */

int main(void) 
{
    // Initialize vectors
    std::vector<int> vec1;                   // Empty vector
    std::vector<int> vecsize(5);             // Zeroed vector of initial size = 5  
    std::vector<int> vec2(5, 10);            // Vector of size 5, all elements are 10
    std::vector<int> vec2_i{5, 10};          // Vector of two elements 5,10
    std::vector<int> vec3 = {1, 2, 3, 4, 5}; // Initializer list
    std::vector<int> vec4(vec3);             // Copy constructor
    std::vector<int> vec5(std::move(vec2));  // Move Constructor

    std::array<int, 5> arr { 1,2,3,4,5};
    std::vector<int> vec6(arr.begin(), arr.end());  // range

    // Accessing elements
    std::cout << "First element of vec3: "  << vec3[0] << std::endl;
    std::cout << "Second element of vec3: " << vec3.at(1) << std::endl;

    // Accessing and Modifying elements
    vec3[0]    = 10;       // Change first element
    vec3.at(1) = 20;    // Change second element (bound checking)

    int frontElement = vec3.front();
    std::cout << "Front element: " << frontElement << std::endl;

    // Access the end (last) element of the vector
    int endElement = vec3.back();
    std::cout << "End element: " << endElement << std::endl;

    // Adding elements
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);

    printVector(vec1, "vec1 after pushing elements : ");


    // Removing elements
    vec1.pop_back(); // Removes the last element

    printVector(vec1, "vec1 after pop_back : ");


    // Inserting elements
    vec1.insert(vec1.begin(), 0);       // Insert 0 at the beginning
    vec1.insert(vec1.begin() + 2, 5);   // Insert 5 at index 2

    printVector(vec1, "vec1 after insert : ");


    // Assigning elements
    vec1.assign({1,2,3,4,5,6,7,8,9});
    printVector(vec1, "vec1 after assign : ");

    vec1.assign(5,1);
    printVector(vec1, "vec1 after assign : ");

    vec2.assign(vec1.begin(), vec1.end());
    printVector(vec2, "vec2 after assign : ");


    // Erasing elements
    vec1.erase(vec1.begin());                   // Erase first element
    vec1.erase(vec1.begin(), vec1.begin() + 2); // Erase first two elements
    printVector(vec1, "vec1 after erase : ");


    // Emplace vs. Push_back
    // Provide optimizations and avoid redundant copying in certain cases
    vec3.emplace(vec3.begin(), 100);                // Inserts 100 at the beginning
    vec3.emplace_back(150);
    vec3.push_back(200);                            // Adds 200 at the end

    printVector(vec3, "vec3 after emplace and push_back: ");

    //   Iterating over a vector
    std::cout << "vec3 elements: ";
    for (int i = 0; i < vec3.size(); ++i) {
        std::cout << vec3[i] << " ";
    }
    std::cout << std::endl;

    //   Using range-based for loop
    std::cout << "vec3 elements using range-based loop: ";
    for (int elem : vec3) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    //   Using iterators
    std::cout << "vec3 elements using iterators: ";
    for (auto it = vec3.begin(); it != vec3.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;


    //   Capacity functions
    std::cout << "Size of vec1: "     << vec1.size()     << std::endl;
    std::cout << "Max Size of vec1: " << vec1.max_size() << std::endl;
    std::cout << "Capacity of vec1: " << vec1.capacity() << std::endl;

    vec1.shrink_to_fit(); // Reduce capacity to fit the size

    std::cout << "Capacity after shrink_to_fit: " << vec1.capacity() << std::endl;

    if (vec1.empty()) {
        std::cout << "The vector is empty." << std::endl;
    } else {
        std::cout << "The vector is not empty." << std::endl;
    }

    // Resizing a vector
    vec2.resize(10, 99); // Resizes vec2 to 10 elements, new elements initialized to 99
    printVector(vec2, "vec2 after resizing: ");

    //  Clearing a vector
    vec2.clear();                               // Removes all elements from vec2
    printVector(vec2, "vec2 after clearing: ");

    //  Sorting a vector
    std::vector<int> vec7 = {4, 2, 3, 1, 5};
    std::sort(vec7.begin(), vec7.end());        // Sort in ascending order
    printVector(vec7, "vec7 sorted: ");

    // Sort in descending order
    std::sort(vec7.begin(), vec7.end(), std::greater<int>());
    printVector(vec7, "vec7 sorted in descending order: ");

    //   Reversing a vector
    std::reverse(vec7.begin(), vec7.end());
    printVector(vec7, "vec7 reversed: ");

    //   Finding an element
    auto it = std::find(vec7.begin(), vec7.end(), 3);
    if (it != vec7.end()) {
        std::cout << "Element 3 found at index: " << it - vec7.begin() << std::endl;
    } else {
        std::cout << "Element 3 not found" << std::endl;
    }

    //   Accumulate elements
    int sum = std::accumulate(vec7.begin(), vec7.end(), 0);
    std::cout << "Sum of vec5 elements: " << sum << std::endl;

    //   Swap two vectors
    printVector(vec3, "Before swap, vec3: ");

    printVector(vec4, "Before swap, vec4: ");

    vec3.swap(vec4);

    printVector(vec3, "After swap, vec3: ");

    printVector(vec4, "After swap, vec4: ");

    //   Using 2D vectors
    std::vector<std::vector<int>> vec2D(3, std::vector<int>(4, 0)); // 3x4 2D vector, all elements initialized to 0
    vec2D[1][2] = 5;                                                // Set the element at row 1, column 2 to 5

    std::cout << "2D vector elements:" << std::endl;
    for (const auto& row : vec2D) {
        for (int elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    //   Vector of pairs
    std::vector<std::pair<int, std::string>> vecPairs;
    vecPairs.emplace_back(1, "one");
    vecPairs.emplace_back(2, "two");

    std::cout << "Vector of pairs:" << std::endl;
    for (const auto& p : vecPairs) {
        std::cout << p.first << " - " << p.second << std::endl;
    }

    return 0;
}
