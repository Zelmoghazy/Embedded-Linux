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
    std::vector<int> v = {1, 2, 3, 4, 5};
    
    // Partition based on a condition
    std::partition(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    // v = {2, 4, 3, 1, 5} (even elements first)

    return 0;
}