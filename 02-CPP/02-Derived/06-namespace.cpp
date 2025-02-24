#include <iostream>
#include <ostream>

int a;

namespace n {
    int a;
}
namespace p {
    int a;
}

namespace f {
    void fn(){
        std::cout << "Function\n";
    }
}

// Anonymous namespace
// only visible in current file
// not resuable outside 
// in c : static int local_var;

namespace {
    int local_var;
}


// a class and a struct are also implicit namespaces

struct Test{
    static int a;
    static int b;
};


// Nested Name soaces
namespace A {
    namespace B {
        namespace C {
            //...
        }
    }
}

// equivalent to since c++17
namespace A::B::C {
    //...
}

int main(void)
{
    a = 5;
    n::a = 6;
    p::a = 7;
    local_var = 20;

    std::cout << a << n::a << p::a << local_var <<std::endl;


    f::fn();

    Test::a = 5;
    Test::b = 6;

    return 0;
}
