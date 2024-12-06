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
    std::vector<int> v = {4, 2, 8, 6, 1};
    
    // Minimum element
    auto minIt = std::min_element(v.begin(), v.end()); // points to 1
    
    // Maximum element
    auto maxIt = std::max_element(v.begin(), v.end()); // points to 8
}