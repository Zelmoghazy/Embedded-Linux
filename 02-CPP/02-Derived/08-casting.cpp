#include <cstddef>
#include <iostream>


class Base {
public:
    virtual void print() {  // must be polymorphic
        std::cout << "Base\n";
    }
};

class Derived : public Base {
public:
    void print() override {
        std::cout << "Derived\n";
    }

    void derivedOnly() {
        std::cout << "Special function in Derived\n";
    }
};

int main(void)
{
    /* C-style cast */
    int a = 10;
    double b = (double)a; 
    std::cout << "(double)a: " << b << std::endl;

    void* p = &a;
    int* q = (int*)p;  
    std::cout << "*q: " << *q << std::endl;

    /* --------------------------------------------- */

    /* 
        reinterpret_cast 
        The reinterpret_cast operator is used for pointer conversions. It does the same as C-
        style type-casting with a little more syntax check. It does not produce any extra code.
    */
    char c = 'a';
    char* ptr = &c;
    int* intptr = reinterpret_cast<int*>(ptr);  // Cast int* to char* allowed but its undefined behaviour
    
    std::cout << *intptr << std::endl;

    /* --------------------------------------------- */

    /* 
        static cast 
        The static_cast operator does the same as the C-style type-casting.
    */
    int a2 = 10;
    double b2 = static_cast<double>(a2);  // Convert int to double
    std::cout << "static_cast<double>(a): " << b2 << std::endl;

    // intptr = static_cast<int*>(ptr); // not allowed (safer)

    /* --------------------------------------------- */

    /* 
        const cast 
        The const_cast operator is used for relieving the const restriction from a pointer. It has
        some syntax checking and is therefore more safe than the C-style type-casting without
        adding any extra code.
    */
    const int a_const = 10;
    const int *ptr_const = &a_const; // allowed pointer to const int

    // int *ptr1 = ptr_const; // error 
    // int *ptr2 = static_cast<int *>(ptr_const); // error
    int *ptr2 = const_cast<int *>(ptr_const);  // allowed

    // More realistc use remove the const-ness from references and pointers 
    // that ultimately refer to something that is not const.
    int i = 0;
    const int& ref = i;
    const int* ptr3 = &i;

    const_cast<int&>(ref) = 3;
    *const_cast<int*>(ptr3) = 3;

    /* --------------------------------------------- */
    /* 
        dynamic cast 
        The dynamic_cast operator is used for converting a pointer to one class to a pointer to
        another class. It makes a runtime check that the conversion is valid. For example, when a
        pointer to a base class is converted to a pointer to a derived class, it checks whether the
        original pointer actually points to an object of the derived class. This check makes
        dynamic_cast more time-consuming than a simple type casting, but also safer. It may
        catch programming errors that would otherwise go undetected.

    */
    Base* b3 = new Derived();  // base pointer pointing to derived object

    // Safe downcast
    Derived* d = dynamic_cast<Derived*>(b3);

    if (d) {
        d->derivedOnly();  // safe to call
    } else {
        std::cout << "Cast failed\n";
    }

    delete b3;
}