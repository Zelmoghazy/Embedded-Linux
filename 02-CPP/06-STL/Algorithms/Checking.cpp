#include <algorithm>
#include <functional>
#include <ios>
#include <iterator>
#include <ostream>
#include <random>
#include <vector>
#include <iostream>
#include <numeric>

void printVector(const std::vector<int>& vec, const char *message) {
    std::cout << message << " ";
    for (int elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main(void)
{
    std::vector<int> v = {2, 4, 6, 8, 10};

    // 1. std::all_of: Check if all elements satisfy a condition
    bool allEven = std::all_of(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    std::cout << "All elements are even: " << (allEven ? "True" : "False") << std::endl;

    // 2. std::any_of: Check if any element satisfies a condition
    bool anyGreaterThanFive = std::any_of(v.begin(), v.end(), [](int x) { return x > 5; });
    std::cout << "Any element greater than 5: " << (anyGreaterThanFive ? "True" : "False") << std::endl;

    // 3. std::none_of: Check if no elements satisfy a condition
    bool noneNegative = std::none_of(v.begin(), v.end(), [](int x) { return x < 0; });
    std::cout << "No elements are negative: " << (noneNegative ? "True" : "False") << std::endl;

    return 0;
}