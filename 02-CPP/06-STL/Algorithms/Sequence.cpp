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
    std::vector<int> v = {1, 2, 3, 4, 5};

    // Apply a function to each element
    std::cout << "Elements (doubled using std::for_each): ";
    std::for_each(v.begin(), v.end(), [](int& x) { x *= 2; });
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;

    v.assign({1, 2, 3, 4, 5});

    int n = 3;
    std::cout << "First " << n << " elements (incremented using std::for_each_n): ";
    std::for_each_n(v.begin(), n, [](int& x) { x += 1; });
    std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;
}