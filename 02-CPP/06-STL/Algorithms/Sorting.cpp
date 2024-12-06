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

int main(void) 
{
    std::vector<int> v = {3, 1, 4, 1, 5, 9};
    
    // Sort in ascending order
    std::sort(v.begin(), v.end()); // {1, 1, 3, 4, 5, 9}
    
    // Sort in descending order
    std::sort(v.begin(), v.end(), std::greater<int>()); // {9, 5, 4, 3, 1, 1}
}