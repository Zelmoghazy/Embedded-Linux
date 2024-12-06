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
    std::vector<int> v = {1, 2, 2, 3, 3, 3};
    
    // Count occurrences of a value
    int count = std::count(v.begin(), v.end(), 3); // count = 3
    std::cout << count << std::endl;    
}