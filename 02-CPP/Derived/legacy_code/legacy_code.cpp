#include "iostream"
#include <ostream>

// Don't mangle !!
extern "C"
{
    #include "cfile.h"
}

void fun(int x)
{
    std::cout << "hello world " << x << std::endl;
}

void fun(int x, int y)
{
    std::cout << "hello world " << x << y << std::endl;
}


int main(void)
{
    fun(2);
    fun(2,3);
    display();
}