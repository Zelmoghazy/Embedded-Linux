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
    
    // Make a heap
    std::make_heap(v.begin(), v.end()); // v = {9, 5, 4, 1, 1, 3}
    
    // Push onto heap
    v.push_back(6);
    std::push_heap(v.begin(), v.end()); // v = {9, 6, 4, 1, 1, 3, 5}
    
    // Pop from heap
    std::pop_heap(v.begin(), v.end()); // v = {6, 5, 4, 1, 1, 3, 9}
    v.pop_back(); // v = {6, 5, 4, 1, 1, 3}
    
    // Sort heap
    std::sort_heap(v.begin(), v.end()); // v = {1, 1, 3, 4, 5, 6}
}