#include <algorithm>
#include <functional>
#include <ios>
#include <iterator>
#include <ostream>
#include <random>
#include <vector>
#include <iostream>
#include <numeric>

void printVector(const std::vector<int>& vec, const char *message) 
{
    std::cout << message << " ";
    for (int elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

bool is_even(int num) 
{
    return num % 2 == 0;
}


int main(void)
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> subVec = {4, 5, 6};

    // Using std::search to find the subsequence subVec in vec
    auto it = std::search(vec.begin(), vec.end(),
                          subVec.begin(), subVec.end());

    if (it != vec.end()) {
        std::cout << "Subsequence found starting at position: "
                  << std::distance(vec.begin(), it) << '\n';
    } else {
        std::cout << "Subsequence not found.\n";
    }

    /* --------------------------------------------------------------------------- */

    // Binary Search: requires sorted container
    bool found = std::binary_search(vec.begin(), vec.end(), 4); // true
    std::cout << std::boolalpha <<  found << std::endl; 

    /* --------------------------------------------------------------------------- */

    // Finding element in a container
    it = std::find(vec.begin(), vec.end(), 3); // it points to 3
    if(it != vec.end())
    {
        std::cout << it.base() << std::endl;
        std::cout << "found at : " << std::distance(vec.begin(), it) << std::endl;
    }
    /* --------------------------------------------------------------------------- */

    std::vector<int> vec2 = {1, 2, 3, 5, 5, 6, 7, 8};

    // Using adjacent_find with a custom predicate to find
    // the first pair where the first element is less than the second
    it = std::adjacent_find(vec2.begin(), vec2.end());

    if (it != vec2.end()) {
        std::cout << "First pair of adjacent equal elements found at position: "
                  << std::distance(vec2.begin(), it) << " with value: " << *it << '\n';
    } else {
        std::cout << "No adjacent equal elements found.\n";
    }

    /* --------------------------------------------------------------------------- */

    std::vector<int> numbers = {1, 3, 5, 7, 8, 9, 11, 13};

    // Using find_if to locate the first even number
    auto it = std::find_if(numbers.begin(), numbers.end(), 
                           is_even);

    if (it != numbers.end()) {
        std::cout << "First even number found: " << *it << std::endl;
    } else {
        std::cout << "No even number found." << std::endl;
    }

    // Alternative using lambda function
    auto lambda_it = std::find_if(numbers.begin(), numbers.end(), 
                                  [](int num) { return num > 10; });

    if (lambda_it != numbers.end()) {
        std::cout << "First number greater than 10: " << *lambda_it << std::endl;
    }
}