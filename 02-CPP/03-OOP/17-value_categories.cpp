#include <iostream>
#include <ostream>


int& fun()
{
    static int a = 5;
    return a;
}

int fun2()
{
    static int a = 5;
    return a;
}

int main(void)
{
    int lvalue = 5;
    (lvalue=5) = 6;

    std::cout << lvalue << std::endl;

    // (lvalue+1) = 6; // error : assigning to an rvalue
    // &lvalue = 6; // assigning to an rvalue

    fun() = 10; // lvalue here as it returns a reference to a
    std::cout << fun() << std::endl;

    int x = fun(); // rvalue here
    std::cout << x << std::endl;

    int b = fun2(); // rvalue
    std::cout << b << std::endl;

    // fun2() = 10; // error rvalue not assignable

    /* ---------------------  */

    // xvalue
    std::string name = "Zeyad";         
    std::string name2 = std::move(name);

    std::cout << name << std::endl;     // Empty -> xvalue expiring lvalue (movable)
    std::cout << name2 << std::endl;

}