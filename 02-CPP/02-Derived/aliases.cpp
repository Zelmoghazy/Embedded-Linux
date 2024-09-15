#include <cstdint>
#include <iostream>
#include <ostream>

int main(void)
{
    // c/c++98
    typedef uint64_t u64;

    // c++11
    using u32 = uint32_t;

    u64 var1 = 150; 
    u32 var2 = 150; 

    std::cout << sizeof(var1) * 8 << " " << sizeof(var2) * 8 << std::endl;

}
