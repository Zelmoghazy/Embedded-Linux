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


void sortingAlgorithms() 
{
    std::vector<int> v = {3, 1, 4, 1, 5, 9};
    
    // Sort in ascending order
    std::sort(v.begin(), v.end()); // {1, 1, 3, 4, 5, 9}
    
    // Sort in descending order
    std::sort(v.begin(), v.end(), std::greater<int>()); // {9, 5, 4, 3, 1, 1}
}

void searchingAlgorithms() 
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> subVec = {4, 5, 6};
    // Using std::search to find the subsequence subVec in vec
    auto it = std::search(vec.begin(), vec.end(), subVec.begin(), subVec.end());

    if (it != vec.end()) {
        std::cout << "Subsequence found starting at position: "
                  << std::distance(vec.begin(), it) << '\n';
    } else {
        std::cout << "Subsequence not found.\n";
    }
    /* --------------------------------------------------------------------------- */

    // Binary Search: requires sorted container
    bool found = std::binary_search(vec.begin(), vec.end(), 4); // true
    std::cout << std::boolalpha <<  found << std::endl; 
    /* --------------------------------------------------------------------------- */

    // Finding element in a container
    it = std::find(vec.begin(), vec.end(), 3); // it points to 3
    if(it != vec.end())
    {
        std::cout << it.base() << std::endl;
        std::cout << "found at : " << std::distance(vec.begin(), it) << std::endl;
    }
    /* --------------------------------------------------------------------------- */

    std::vector<int> vec2 = {1, 2, 3, 5, 5, 6, 7, 8};

    // Using adjacent_find with a custom predicate to find the first pair where the first element is less than the second
    it = std::adjacent_find(vec2.begin(), vec2.end());

    if (it != vec2.end()) {
        std::cout << "First pair of adjacent equal elements found at position: "
                  << std::distance(vec2.begin(), it) << " with value: " << *it << '\n';
    } else {
        std::cout << "No adjacent equal elements found.\n";
    }

}

void checkingAlgorithms()
{
    std::vector<int> v = {2, 4, 6, 8, 10};

    // 1. std::all_of: Check if all elements satisfy a condition
    bool allEven = std::all_of(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    std::cout << "All elements are even: " << (allEven ? "True" : "False") << std::endl;

    // 2. std::any_of: Check if any element satisfies a condition
    bool anyGreaterThanFive = std::any_of(v.begin(), v.end(), [](int x) { return x > 5; });
    std::cout << "Any element greater than 5: " << (anyGreaterThanFive ? "True" : "False") << std::endl;

    // 3. std::none_of: Check if no elements satisfy a condition
    bool noneNegative = std::none_of(v.begin(), v.end(), [](int x) { return x < 0; });
    std::cout << "No elements are negative: " << (noneNegative ? "True" : "False") << std::endl;
}

void countingAlgorithms() 
{
    std::vector<int> v = {1, 2, 2, 3, 3, 3};
    
    // Count occurrences of a value
    int count = std::count(v.begin(), v.end(), 3); // count = 3
    std::cout << count << std::endl;
}

void Sequence_algorithms()
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

void minMaxAlgorithms() 
{
    std::vector<int> v = {4, 2, 8, 6, 1};
    
    // Minimum element
    auto minIt = std::min_element(v.begin(), v.end()); // points to 1
    
    // Maximum element
    auto maxIt = std::max_element(v.begin(), v.end()); // points to 8
}


void permutationAlgorithms() 
{
    std::vector<int> v = {1, 2, 3};
    
    // Next permutation
    std::next_permutation(v.begin(), v.end()); // {1, 3, 2}
    
    // Previous permutation
    std::prev_permutation(v.begin(), v.end()); // {1, 2, 3} (back to original)
}


void setOperations() 
{
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {2, 3, 4};
    std::vector<int> result;

    // Union
    std::set_union(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result)); 
    // result = {1, 2, 3, 4}

    // Intersection
    result.clear();
    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result));
    // result = {2, 3}

    // Difference
    result.clear();
    std::set_difference(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result));
    // result = {1}

    // Symmetric Difference
    result.clear();
    std::set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(result));
    // result = {1, 4}
}

void mismatch() 
{
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::vector<int> v2 = {1, 2, 0, 4, 5};

    // Find the first position where the two ranges differ
    auto mismatchPair = std::mismatch(v1.begin(), v1.end(), v2.begin());

    if (mismatchPair.first != v1.end()) 
    {
        std::cout << "Mismatch found at index "
                  << std::distance(v1.begin(), mismatchPair.first) << ":\n";

        std::cout << "v1 has "      << *mismatchPair.first 
                  << " and v2 has " << *mismatchPair.second << std::endl;
    } else {
        std::cout << "No mismatch found; the ranges are identical." << std::endl;
    }
}


void numericAlgorithms()
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

void modifyingAlgorithms() 
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
}

void modifyingSequence()
{
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

void partitioningAlgorithms() 
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    
    // Partition based on a condition
    std::partition(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    // v = {2, 4, 3, 1, 5} (even elements first)
}

void heapAlgorithms() 
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

void parallelAlgorithms()
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

int main(void) 
{
    sortingAlgorithms();
    searchingAlgorithms();
    countingAlgorithms();
    minMaxAlgorithms();
    permutationAlgorithms();
    setOperations();
    numericAlgorithms();
    modifyingAlgorithms();
    partitioningAlgorithms();
    heapAlgorithms();
    modifyingSequence();
    parallelAlgorithms();

    return 0;
}
