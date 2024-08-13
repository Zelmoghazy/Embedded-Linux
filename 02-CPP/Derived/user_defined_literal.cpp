#include <iostream>
#include <ostream>
#include <string>


void operator""_print(const char *msg, size_t size){
    std::cout << msg << std::endl;
}

int main(void)
{
    "Hello"_print;
    return 0;
}