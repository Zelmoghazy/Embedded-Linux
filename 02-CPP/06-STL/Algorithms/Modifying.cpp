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
    
    // Reverse
    std::reverse(v.begin(), v.end()); // v = {5, 4, 3, 2, 1}
    
    // Rotate
    std::rotate(v.begin(), v.begin() + 2, v.end()); // v = {3, 2, 1, 5, 4}
    
    // Shuffle
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(),g); // v = {random order}

    // Original vector
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> dest(5);

    // std::copy
    std::copy(vec.begin(), vec.end(), dest.begin());
    printVector(dest, "After std::copy: ");

    // std::transform - multiply each element by 2
    std::vector<int> tmpvec;
    std::transform(vec.begin(), vec.end(), std::back_inserter(tmpvec), [](int x) { return x * 2; });
    printVector(tmpvec, "After std::transform (multiply by 2): ");

    // std::replace - replace 4 with 10
    std::replace(vec.begin(), vec.end(), 4, 10);
    printVector(vec, "After std::replace (4 with 10): ");

    // std::fill - fill the vector with 7
    std::fill(vec.begin(), vec.end(), 7);
    printVector(vec, "After std::fill (with 7): ");

    // std::remove - remove all 7s (this doesn't resize the vector)
    auto new_end = std::remove(vec.begin(), vec.end(), 7);
    vec.erase(new_end, vec.end()); // optional, to actually remove from the vector
    printVector(vec, "After std::remove (all 7s): ");

    // Reset the vector
    vec = {1, 2, 3, 2, 4, 2, 5};

    // Example 2: std::remove_copy
    // Copy all elements except '2' into a new vector
    std::vector<int> vec_copy;
    std::remove_copy(vec.begin(), vec.end(), std::back_inserter(vec_copy), 2);
    printVector(vec, "After std::remove_copy: ");
}