#include <cstddef>
#include <iostream>

int main(void)
{
    /* C-style cast */
    int a = 10;
    double b = (double)a; 
    std::cout << "(double)a: " << b << std::endl;

    void* p = &a;
    int* q = (int*)p;  
    std::cout << "*q: " << *q << std::endl;

    /* reinterpret_cast */
    char c = 'a';
    char* ptr = &c;
    int* intptr = reinterpret_cast<int*>(ptr);  // Cast int* to char* allowed but its undefined behaviour
    
    std::cout << *intptr << std::endl;

    /* static cast */
    int a2 = 10;
    double b2 = static_cast<double>(a2);  // Convert int to double
    std::cout << "static_cast<double>(a): " << b2 << std::endl;

    // intptr = static_cast<int*>(ptr); // not allowed (safer)

    /* const cast */
    // used to add or remove const qualifiers

    const int a_const = 10;
    const int *ptr_const = &a_const; // allowed pointer to const int

    // int *ptr1 = ptr_const; // error 
    // int *ptr2 = static_cast<int *>(ptr_const); // error
    int *ptr2 = const_cast<int *>(ptr_const);  // allowed

    // More realistc use remove the const-ness from references and pointers that ultimately refer to something that is not const.
    int i = 0;
    const int& ref = i;
    const int* ptr3 = &i;

    const_cast<int&>(ref) = 3;
    *const_cast<int*>(ptr3) = 3;
}