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
    printVector(v, "Original vector: ");

    // Reverse
    std::reverse(v.begin(), v.end()); // v = {5, 4, 3, 2, 1}
    printVector(v, "Reverse: ");
    
    // Rotate
    std::rotate(v.begin(), v.begin() + 2, v.end()); // v = {3, 2, 1, 5, 4}
    printVector(v, "Rotate: ");

    // Shuffle
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v.begin(), v.end(),g); // v = {random order}
    printVector(v, "Shuffle: ");

    std::cout << "---------------------------------\n";

    
    std::vector<int> vec = {1, 2, 3, 4, 5}; // Original vector
    std::vector<int> dest(5);               // Destination vector

    // std::copy
    std::copy(vec.begin(), vec.end(), dest.begin());
    printVector(dest, "After std::copy: ");

    // std::transform - multiply each element by 2
    std::vector<int> tmpvec;
    std::transform(vec.begin(), vec.end(),          // Original
                   std::back_inserter(tmpvec),      // start result
                   [](int x) { return x * 2; });    // function 
    printVector(tmpvec, "After std::transform (multiply by 2): ");

    tmpvec.clear();

    std::vector<int> multiples = {2, 2, 2, 2, 2};
    std::transform(vec.begin(), vec.end(),          // Original
                   multiples.begin(),               // start multiplier
                   std::back_inserter(tmpvec),      // start result
                   std::multiplies<int>());         // function
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

    // Copy all elements except '2' into a new vector
    std::vector<int> vec_copy;
    std::remove_copy(vec.begin(), vec.end(), std::back_inserter(vec_copy), 2);
    printVector(vec, "After std::remove_copy: ");

    return 0;
}