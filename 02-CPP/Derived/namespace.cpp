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

int main(void)
{
    a = 5;
    n::a = 6;
    p::a = 7;
    local_var = 20;

    std::cout << a << n::a << p::a << local_var <<std::endl;

    f::fn();

}
