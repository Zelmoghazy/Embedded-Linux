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
    std::vector<int> v = {1, 2, 3};
    
    // Next permutation
    std::next_permutation(v.begin(), v.end()); // {1, 3, 2}
    
    // Previous permutation
    std::prev_permutation(v.begin(), v.end()); // {1, 2, 3} (back to original)
}
