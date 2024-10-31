#include <iostream>

/*
    Compiler will search for functions
    in the scope from which its parameter type are defined
    This only applies to namespaces not classes
 */

namespace A
{
    struct X{};
    void g(X){
        std::cout << "Calling A::g() \n";
    }
}


int main(void)
{
    A::X x1;

    A::g(x1);
    g(x1);      // no compiler error although we didnt specify namespace as its in scope of x1


    return 0;
}