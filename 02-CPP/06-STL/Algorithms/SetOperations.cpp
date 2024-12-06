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
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {2, 3, 4};
    std::vector<int> result;

    // Union
    std::set_union(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result)); 
    // result = {1, 2, 3, 4}

    // Intersection
    result.clear();
    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result));
    // result = {2, 3}

    // Difference
    result.clear();
    std::set_difference(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result));
    // result = {1}

    // Symmetric Difference
    result.clear();
    std::set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result));
    // result = {1, 4}
}
