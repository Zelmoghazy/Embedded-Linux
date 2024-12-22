
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main(void) 
{
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // using range based for loop
    for(auto a : vec)
    {
        std::cout << a << " ";
    }
    std::cout << std::endl;
    

    // Using a regular iterator
    std::vector<int>::iterator it;
    for (it = vec.begin();
         it != vec.end();
         ++it) 
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Using a reverse iterator
    std::vector<int>::reverse_iterator rit;
    for (rit = vec.rbegin();
         rit != vec.rend();
         ++rit) 
    {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    // Using an ostream_iterator
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}