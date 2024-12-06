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
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2 = {1, 2, 0, 4, 5};

    // Find the first position where the two ranges differ
    auto mismatchPair = std::mismatch(v1.begin(), v1.end(), v2.begin());

    if (mismatchPair.first != v1.end()) 
    {
        std::cout << "Mismatch found at index "
                  << std::distance(v1.begin(), mismatchPair.first) << ":\n";

        std::cout << "v1 has "      << *mismatchPair.first 
                  << " and v2 has " << *mismatchPair.second << std::endl;
    } else {
        std::cout << "No mismatch found; the ranges are identical." << std::endl;
    }
}