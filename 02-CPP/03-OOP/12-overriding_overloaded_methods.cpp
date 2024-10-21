#include <string>
#include <iostream>

class BaseClass {
public:
    int foo(std::string);
    int foo(int);
};

class DerivedClass1 : BaseClass {
public:
    int foo(std::string);
};

class DerivedClass2 : BaseClass {
public:
    using BaseClass::foo;
    int foo(std::string);
};

int main(void)
{
    DerivedClass1 dc;
    // dc.foo(4);          // Error : overriding an overloaded method will hide the others

    DerivedClass2 dc2;
    dc2.foo(5);            // OK inheriting all overloads with "using" 
}