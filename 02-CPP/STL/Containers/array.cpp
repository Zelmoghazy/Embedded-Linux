#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>  // for std::accumulate
#include <iterator> // for std::begin, std::end


constexpr int MAX_SIZE = 5;

class BoxedString : public std::array<char, MAX_SIZE>{
    public:
        BoxedString(const char *str)
        {
            std::copy(str, str+MAX_SIZE, std::array<char, MAX_SIZE>::begin());
        }

        void print() const {
            std::for_each(begin(), end(), [](char c){std::cout << c;});
            std::cout << std::endl;
        }
};


int main(void) 
{
    // 1. Declaration and Initialization
    std::array<int, 5> arr1 = {1, 2, 3, 4, 5};
    std::array<int, 5> arr2 = {10, 20}; // Rest will be initialized to 0

    // 2. Access elements
    std::cout << "First element: "  << arr1[0]       << "\n";
    std::cout << "Second element: " << arr1.at(1)   << "\n"; // bounds-checked access
    // std::cout << "Exceed last pos: " << arr1.at(6) << "\n"; // Throws out of range exception

    // 3. Size of the array
    std::cout << "Size of arr1: " << arr1.size() << "\n";
    std::cout << "Size of arr1: " << arr1.max_size() << "\n";
    std::cout << "Is array empty ? : " << std::boolalpha <<  arr1.empty() << "\n";

    // 4. Front and Back
    std::cout << "Front of arr1: " << arr1.front() << "\n";     // first value
    std::cout << "Back of arr1: " << arr1.back() << "\n";       // last value

    std::cout << "Starting address of arr1: " << arr1.begin() << "\n";
    std::cout << "Ending address of arr1: " << arr1.end() << "\n";

    // 5. Iterating over the array
    std::cout << "Elements of arr1: ";
    for (const auto& elem : arr1) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    // 6. Filling the array with a specific value
    arr2.fill(42);
    std::cout << "arr2 after fill: ";
    for (const auto& elem : arr2) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    // 7. Swap two arrays
    arr1.swap(arr2);
    std::cout << "arr1 after swap: ";
    for (const auto& elem : arr1) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    // 8. Accessing raw array data
    int* raw_data = arr1.data();
    std::cout << "Raw data of arr1: ";
    for (size_t i = 0; i < arr1.size(); ++i) {
        std::cout << raw_data[i] << " ";
    }
    std::cout << "\n";

    // 9. Using std::sort on std::array
    std::array<int, 6> arr3 = {5, 2, 8, 3, 1, 4};
    std::sort(arr3.begin(), arr3.end());
    std::cout << "arr3 after sort: ";
    for (const auto& elem : arr3) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    // 10. Using std::reverse on std::array
    std::reverse(arr3.begin(), arr3.end());
    std::cout << "arr3 after reverse: ";
    for (const auto& elem : arr3) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    // 11. Sum of elements using std::accumulate
    int sum = std::accumulate(arr3.begin(), arr3.end(), 0);
    std::cout << "Sum of elements in arr3: " << sum << "\n";

    // 12. Check if array is sorted
    bool is_sorted = std::is_sorted(arr3.begin(), arr3.end());
    std::cout << "Is arr3 sorted? " << (is_sorted ? "Yes" : "No") << "\n";

    // 13. Finding an element
    auto it = std::find(arr3.begin(), arr3.end(), 3);
    if (it != arr3.end()) {
        std::cout << "Element 3 found at index: " << std::distance(arr3.begin(), it) << "\n";
    } else {
        std::cout << "Element 3 not found.\n";
    }

    // 14. Creating an array of different types
    std::array<std::string, 3> arr4 = {"Hello", "Array", "World"};
    std::cout << "arr4: ";
    for (const auto& elem : arr4) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    // 15. Multi-dimensional array
    std::array<std::array<int, 3>, 2> arr5 = {{{1, 2, 3}, {4, 5, 6}}};
    std::cout << "arr5 elements:\n";
    for (const auto& row : arr5) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << "\n";
    }

    // Boxed String

    BoxedString bs("Hello World");
    bs.print();

    return 0;
}
