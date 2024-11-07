#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <ostream>


/*
    - Copy elision is an optimization technique in C++ where the compiler
      can omit the creation of temporary objects in certain situations, 
      effectively "eliding" or skipping unnecessary copy and move constructors.

    - This reduces overhead by avoiding redundant object construction, 
      copy, or move operations, which improves performance.

    1- Return Value Optimization (RVO): When a function returns a local object by value, 
      instead of copying the object to the caller, the compiler can construct the object
      directly in the caller's space. 

    2- Named Return Value Optimization (NRVO): Similar to RVO, but specifically applies
       when the returned object has a name. The compiler can directly construct the named
       object in the caller's memory.

    3- Temporary Object Optimization: When creating temporary objects in expressions, 
       copy elision allows the compiler to avoid creating intermediate temporary objects,
       constructing them directly where they are needed.

    Compile using -fno-elide-constructors
    and -std=c++14
 */

class String{
    private:
        const char* str;
        uint64_t size;
    
    public:
        String(){
            std::cout << "Default Constructor!\n";
        }

        ~String() {
            std::cout << "Default Destructor!\n";
        }
        String(const char* str) : str(str){
            size = strlen(str);
        }

        // copy constructor
        String (const String &obj){
            std::cout << "Copy Constructor!\n";
        }

        void display()
        {
            std::cout << str << ' ' << size << std::endl;
        }
};

String get_instance()
{
    String str{};   // default constructor
    return str;     // copy constructor
    // default destructor
}


struct Foo {
    Foo() {}
    Foo(const Foo &) = delete;      // no copy constructor
    Foo(Foo &) = delete;            // no move constructor
};

Foo f() {
    return Foo();
}

int main(void)
{
    {
        String s1(get_instance()); // copy constructor
    }

    std::cout << "-----------------------\n";

    {
        String &&s2(get_instance()); // copy from temp to s2 didnt happen 
    }
    std::cout << "-----------------------\n";

    {
        Foo foo = f();      // only compiles because of elision as we deleted both move and copy constructor
    }

    return 0;
}
