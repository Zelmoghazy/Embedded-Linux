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

    // Accumulate (sum)
    int sum = std::accumulate(v.begin(), v.end(), 0); // sum = 15
    std::cout << "sum : " << sum << std::endl;

    int mult = std::accumulate(v.begin(), v.end(), 1.0, std::multiplies<>);
    std::cout << "mult : " << mult << std::endl;

    // Inner Product
    int product = std::inner_product(v.begin(), v.end(), v.begin(), 0); // product = 55

    // Partial Sum
    std::vector<int> result(v.size());
    std::partial_sum(v.begin(), v.end(), result.begin()); // result = {1, 3, 6, 10, 15}

    // Adjacent Difference
    std::adjacent_difference(v.begin(), v.end(), result.begin()); // result = {1, 1, 1, 1, 1}
}