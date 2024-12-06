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

    fun(&x);        // by pointer
    fun(x);         // by reference

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

    /*
        std::reference_wrapper 
            - Reassignable - unlike regular references, you can make it refer to different objects
            - Can be stored in standard containers (unlike regular references)
            - Guaranteed to never be null (must be initialized)
    */
    #include <string>

    // Declaration

    std::string str1 = "Hello World";
    std::string str2 = "Hello Everone";

    std::reference_wrapper<std::string> ref = str1;

    // Can be reassigned
    bool cond = false;
    if(cond) {
        ref = str1;
    } else {
        ref = str2;
    }

    // To use the referenced value, you need to call get() or implicitly convert
    ref.get() = "new value";  // Explicit
    std::string& str_ref = ref;  // Implicit conversion to reference

    return 0;
}

#include <iostream>
#include <string>
#include <functional>

#define ref         0
#define ref_wrap    1

struct new_str 
{
    std::string used;
    new_str()
    {
        used = "Hello world";
    }
    std::string& get_str()
    {
        return this->used;
    }
};


int main(void) 
{
    std::string temp = "temp";
    new_str str;

#if ref_wrap    
    std::reference_wrapper<std::string> response = temp;
    response = str.get_str();
#endif

#if ref
    std::string &test = temp;
    test = str.get_str();
#endif

#if ref_wrap
    response.get()[0] = 'z';

    std::cout << temp << std::endl;
    std::cout << str.used << std::endl;
    std::cout << response.get() << std::endl;
#endif

#if ref
    test[0] = 'z';

    std::cout << temp << std::endl;
    std::cout << str.used << std::endl;
    std::cout << test << std::endl;
#endif

    return 0;
}
