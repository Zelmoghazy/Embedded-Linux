#include <iostream>
#include <ostream>

int var = 20;

int main(void)
{
    // declare variable inside if statement c++17
    // i is visible only inside the if statement
    // reducing its scope
    if(int i = 15; i < var)
    {
        i = 13;
        std::cout << i <<std::endl;
    }else{
        i = 20;
        std::cout << i <<std::endl;
    }
    return 0;
}