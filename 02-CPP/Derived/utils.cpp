#include <bitset>
#include <iostream>
#include <ostream>

int main(void)
{
    /* Convert from decimal to binary */
    int dec = 15;
    std::cout << std::bitset<8>(15) << std::endl;

    /* Find a number in an array */

    int arr[] = {5,7,4,2,8,6,1,9,0,3};

    auto v = std::find(std::begin(arr),std::end(arr),9);
    std::cout << *v << std::endl;

    /* Convert from a string to any other data type */

    auto i = std::stol("1234");
    std::cout << typeid(i).name() << std::endl;
}