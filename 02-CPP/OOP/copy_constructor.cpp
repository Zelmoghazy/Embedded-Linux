#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <ostream>

class String{
    private:
        char* str;
        uint64_t size;
    
    public:
        String(char* str) : str(str){
            size = strlen(str);
        }
        /* 
            Implicit copy constructor is generated if no copy 
            constructor exits, useful if all members are 
            trivial data type.
         */

        // Explicit copy constructor
        // copy constructor must pass its first argument as a reference to avoid infinite loop.
        // T (const T& obj){}
        String (const String &obj){
            size = obj.size + 1;
            str = new char[size]; // allocate in heap
            strcpy(str,obj.str);
        }

        void display()
        {
            std::cout << str << ' ' << size << std::endl;
        }

        void change_char(char ch, uint64_t idx){
            assert(idx < size);
            str[idx] = ch;
        }
};

String get_instance()
{
    static char arr[] = "New Temporary Instance!";
    String str {arr};
    return str;
}

int main(void)
{
    char arr[] = "Hello world";
    String s1(arr);
    String s2(s1); // this calls the compiler generated copy constructor

    s1.change_char('a', 0);

    // default copy constructor
    s1.display();
    s2.display(); // effects happen also on s2 (shallow copy)

    // Explicit copy constructor
    s1.display();
    s2.display(); // effects happen also on s2 (shallow copy)

    // get_instance() will return a temporary object
    // thus we must make the copy constructor const (RVALUE)
    String s3(get_instance());
    s3.display();

    return 0;
}
