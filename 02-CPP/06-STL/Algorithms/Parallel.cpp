#include <algorithm>
#include <functional>
#include <ios>
#include <iterator>
#include <ostream>
#include <random>
#include <vector>
#include <iostream>
#include <numeric>
#include <execution>

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
    std::vector<int> data(1000000, 1);
    // Multiply each element by 2 in parallel
    std::for_each(std::execution::par, data.begin(), data.end(), [](int &n) { n *= 2; });
    // Print first 10 results
    for (int i = 0; i < 10; ++i)
        std::cout << data[i] << " ";

    // ------------------------------------------------------------------------    

    std::vector<int> data1(1000000, 1);
    std::vector<int> data2(1000000, 2);
    std::vector<int> result(1000000);

    // Add elements from data1 and data2 in parallel
    std::transform(std::execution::par, data1.begin(), data1.end(), data2.begin(), result.begin(), [](int a, int b) {
        return a + b;
    });

    // Print first 10 results
    for (int i = 0; i < 10; ++i)
        std::cout << result[i] << " ";

    // ------------------------------------------------------------------------ 

    std::vector<int> data = {5, 1, 7, 3, 4, 9, 2, 6, 8, 0};

    // Sort the data in parallel
    std::sort(std::execution::par, data.begin(), data.end());

    // Print the sorted results
    for (int n : data)
        std::cout << n << " ";   

    // ------------------------------------------------------------------------ 

    std::vector<int> data(1000000, 1);

    // Sum all elements in parallel
    int sum = std::reduce(std::execution::par, data.begin(), data.end());

    std::cout << "Sum: " << sum << std::endl;

    // ------------------------------------------------------------------------ 

    std::vector<int> data = {10, 25, 40, 55, 70, 85, 100};

    // Find first element greater than 50 in parallel
    auto result = std::find_if(std::execution::par, data.begin(), data.end(), [](int n) { return n > 50; });

    if (result != data.end())
        std::cout << "Found: " << *result << std::endl;

    // ------------------------------------------------------------------------ 

    std::vector<int> data(1000000, 5);

    // Count elements equal to 5 in parallel
    int count = std::count_if(std::execution::par, data.begin(), data.end(), [](int n) { return n == 5; });

    std::cout << "Count of 5s: " << count << std::endl;

    // ------------------------------------------------------------------------

    std::vector<int> source(1000000, 1);
    std::vector<int> destination(1000000);

    // Copy elements in parallel
    std::copy(std::execution::par, source.begin(), source.end(), destination.begin());

    // Verify by printing first 10 elements
    for (int i = 0; i < 10; ++i)
        std::cout << destination[i] << " "; 

    // ------------------------------------------------------------------------

    std::vector<int> data(1000000);

    // Fill with value 10 in parallel
    std::fill(std::execution::par, data.begin(), data.end(), 10);

    // Print first 10 results
    for (int i = 0; i < 10; ++i)
        std::cout << data[i] << " ";

    // ------------------------------------------------------------------------

    std::vector<int> data = {1, 2, 3, 4, 5};
    std::vector<int> result(data.size());

    // Exclusive prefix sum in parallel
    std::exclusive_scan(std::execution::par, data.begin(), data.end(), result.begin(), 0);

    // Print results
    for (int n : result)
        std::cout << n << " ";
    
}
