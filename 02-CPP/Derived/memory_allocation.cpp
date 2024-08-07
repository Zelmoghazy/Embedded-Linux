#include <cstddef>
#include <iostream>


// nullptr vs NULL

void f(int x)
{
    std::cout << "int x" << '\n';
}

void f(int *x)
{
    std::cout << "int *x" << '\n';
}


void fun(int *ptr)
{
    std::cout << "int* ptr\n";
}

void fun(int &ref)
{
    ref = 100;
    std::cout << "int &ref\n";
}

int main(void)
{
    // f(NULL);    // ambigous
    f(nullptr); // calls f(int *x)

    /* ------------------------------ */

    // Dynamic memory allocation

    int* arr = new int[5];

    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 10;
    }

    std::cout << "Array values: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Free the allocated array memory
    delete[] arr;
    arr = nullptr;

    /* ------------------------------ */
    // References vs Pointers

    int x = 10;

    // int &ref;   // error require initialization
    int *ptr;   // not an error

    int &refx = x;      // reference to x
    int *ptrx = &x;     // pointer to x


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
}

