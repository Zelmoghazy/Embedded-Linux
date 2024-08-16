#include <iostream>
#include <ostream>
#include <utility>

void fun(const int &x)
{
}

int main(void)
{
    int y = 10;
    // type category of x is lvalue reference
    // its an alias to lvalue
    int &x = y;

    std::cout << y <<std::endl;
    std::cout << x <<std::endl;
    std::cout << "------------------" <<std::endl;

    x = 12;
    std::cout << y <<std::endl;
    std::cout << x <<std::endl;
    std::cout << "------------------" <<std::endl;

    int y2 = x;
    y2 = 5;

    std::cout << y <<std::endl;
    std::cout << x <<std::endl;
    std::cout << y2 <<std::endl;


    /* ---------------------------------- */

    /* 
        An rvalue reference is a reference that must be bound to an rvalue.
        An rvalue reference is obtained by using && rather than &.
        They have an important property that they may be bound only to an object that is about to be destroyed.
        As a result, we are free to “move” resources from an rvalue reference to another object.

        A variable is an lvalue; we cannot directly bind an rvalue reference to a variable even if that variable was defined as an rvalue reference type.
     */

    // type category of rvalueref is a right value reference
    int &&rvalueref = 10;
    // int &&rvalueref2 = rvalueref; // error rvalueref is lvalue

    int &&rvalueref2 = std::move(rvalueref); // Although we cannot directly bind an rvalue reference to an lvalue, we can explicitly cast an lvalue to its corresponding rvalue reference type.
    // we cannot use rvalueref again unless we assign new value to it
    


    int i = 42;
    int &r = i;         //  ok: r refers to i
    
    // int &&rr = i;       // error: cannot bind an rvalue reference to an lvalue

    // int &r2 = i * 42; // error: i * 42 is an rvalue
    
    
    const int &r3 = i * 42; // ok: we can bind a reference to const to an rvalue
    
    int &&rr2 = i * 42; // ok: bind rr2 to the result of the multiplication
    int &&rr3 = std::move(i); // ok


    std::string name = "Zeyad";
    std::string&& name2 = std::move(name);

    // std::cout << name << std::endl; // undefined behaviour
    std::cout << name2 << std::endl;
    

    /* ---------------------------------- */

    int var = 10 ;
    int &ref = var;


    /* void fun(int x) */
    fun(10); // ok

    fun(var); // ok 
    fun(ref); // ok


    /* void fun(int &x) */
    fun(10); // error

    fun(var); // ok 
    fun(ref); // ok

    /* void fun(const int &x) */
    // we can bind a reference to const to an rvalue
    // const int &ref2 = 10; // ref is an alias to a temporary variable with a value of 10
    // std::cout << &ref2; 
    
    fun(10);  // ok

    fun(var); // ok 
    fun(ref); // ok


    return 0;
}