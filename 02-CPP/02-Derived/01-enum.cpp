#include <iostream>
#include <cstdint>
#include <ostream>


// Scoped enumeration also known as enum class
enum class color : uint8_t{
    RED,
    GREEN,
    BLUE
};

enum class vehicle : uint8_t{
    BUS,
    CAR,
    PLANE
};

std::ostream& operator<<(std::ostream& os, color c) {
    switch (c) {
        case color::RED:
            os << "RED";
            break;
        case color::GREEN:
            os << "GREEN";
            break;
        case color::BLUE:
            os << "BLUE";
            break;
        default:
            os << "UNKNOWN";
            break;
    }
    return os;
}

void fun(color c)
{
    c = color::RED;
    return;
}

char * keytostr(color key)
{
    #define CASE(X)             \
        case X:                 \
            return #X;          
    switch(key)
    {
        CASE(color::RED);
        CASE(color::BLUE);
        CASE(color::GREEN);
    }
    #undef CASE
    return "";
}


int main (void)
{
    // scoping avoid name clashes
    // no automatic conversion to int
    color c = color::BLUE;

    // if(c==2) // Error !
    
    vehicle v = vehicle::PLANE;

    // if(v==c) // Error;

    color obj{};
    std::cout << obj << std::endl;  // invalid unless we specify a method to print it and overload the operator

    std::cout << sizeof(obj) << std::endl; // can specify size

    // int number = color::RED;  // compiler error cannot convert enum to int
    // fun(1);  // error
    std::cout<<keytostr(color::BLUE)<<std::endl;

    return 0;
}