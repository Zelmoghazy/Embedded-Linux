#include <iostream>

// pass by pointer
void fun(int *ptr)
{
    std::cout << "int* ptr\n";
}

// pass by reference
void fun(int &ref)
{
    ref = 100;
    std::cout << "int &ref\n";
}

int main(void)
{

    // References vs Pointers

    /*
        References will never be nullptr
        thus cannot reference temporary objects
    */
    
    int x = 10;

    // int &ref;    // Error require initialization
    int *ptr;       // not an error

    int &refx = x;      // reference to x
    int *ptrx = &x;     // pointer to x

    refx  = 12;      
    *ptrx = 12;         

    std::cout << x      << '\n';
    std::cout << refx   << '\n';
    std::cout << *ptrx  << '\n';

    std::cout << &x     << '\n';
    std::cout << &refx  << '\n';  // same address as x
    std::cout << ptrx   << '\n';  
    std::cout << &ptrx  << '\n';  // a pointer has its own address

    fun(&x);
    fun(x);

    std::cout << x << std::endl;

    int y = 20;

    refx = y;

    std::cout << x      << '\n';
    std::cout << refx   << '\n';

    // const reference
    int z = 30;
    const int &refz = z;

    std::cout << z << std::endl;
    // refz = 15; error cannot modify through a const reference


    return 0;
}