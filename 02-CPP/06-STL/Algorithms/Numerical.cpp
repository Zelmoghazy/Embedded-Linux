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

    /*
        first, last , initial value, op which is :
        binary operation function object that will be applied.
        The signature of the function should be equivalent to the following:
        Ret fun(const Type1 &a, const Type2 &b);
    */
    int mult = std::accumulate(v.begin(), v.end(), 1.0, std::multiplies<>);
    std::cout << "mult : " << mult << std::endl;

    std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};

    int max_sum = nums[0];
    std::accumulate(nums.begin(), nums.end(), 0, 
    [&max_sum](int total, int current) 
    {
        total+=current;
        max_sum = total>max_sum?total:max_sum;
        if((total)<0){total=0;}
        return total;
    });

    // Inner Product i.e. sum of products)
    int product = std::inner_product(v.begin(), v.end(), v.begin(), 0); // product = 55

    // Partial Sum
    std::vector<int> result(v.size());
    std::partial_sum(v.begin(), v.end(), result.begin()); // result = {1, 3, 6, 10, 15}
    // in reverse
    std::partial_sum(v.rbegin(), v.rend(), result.rbegin());


    std::vector data{3, 1, 4, 1, 5, 9, 2, 6};
    std::cout << "\nInclusive sum: ";
    std::inclusive_scan(data.begin(), data.end(),
                        std::ostream_iterator<int>(std::cout, " "));


    std::cout << "Exclusive sum: ";
    std::exclusive_scan(data.begin(), data.end(),
                        std::ostream_iterator<int>(std::cout, " "),
                        0);

    // Adjacent Difference - computes the differences between adjacent elements in a range
    std::adjacent_difference(v.begin(), v.end(), result.begin()); // result = {1, 1, 1, 1, 1}
}