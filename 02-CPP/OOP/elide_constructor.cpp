#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <ostream>


/*
    Compile using -fno-elide-constructors
    and -std=c++14
 */

class String{
    private:
        char* str;
        uint64_t size;
    
    public:
        String(){
            std::cout << "Default Constructor!\n";
        }

        ~String() {
            std::cout << "Default Destructor!\n";
        }
        String(char* str) : str(str){
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
    String str; // default constructor
    return str; // copy constructor
    // default destructor
}

int main(void)
{
    String s1(get_instance()); // copy constructor

    return 0;
}
