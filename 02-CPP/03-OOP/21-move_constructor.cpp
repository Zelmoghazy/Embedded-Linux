#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <new>
#include <ostream>
#include <string.h>


/*
    move constructors and move assignment operators
    offer control over the semantics of moving.

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
            // delete [] str;
        }
        String(char* str){
            size = strlen(str);
            this->str = new char[size+1];
            strcpy(this->str,str);
            std::cout << "Called Constructor!\n";
        }

        // copy constructor
        String (const String &obj)
        {
            size = obj.size;
            str = new char[size+1];
            strcpy(str,obj.str);
            std::cout << "Copy Constructor!\n";
        }

        // move constructor
        /* 
            Like the copy constructor, the move constructor has an 
            initial parameter that is a reference to the class type.
            Differently from the copy constructor, the reference parameter 
            in the move constructor is an rvalue reference. 

            - not const because its going to be modifed (destroying the resource)
         */
        String (String &&obj){
            size = obj.size;
            obj.size = 0;
            str = obj.str;
            obj.str = nullptr;
            std::cout << "Move Constructor!\n";
        }

        void display()
        {
            std::cout << str << ' ' << size << std::endl;
        }
};

String get_instance()
{
    String str{"Hello"};   // default constructor
    return str;     // copy constructor
    // default destructor
}

int main(void)
{
    {
        char str[]="Zeyad";
        String t1{str};
        t1.display();
    }

    std::cout << "--------------------------\n";

    {
        String &&t2{get_instance()};
        t2.display();
    }

    std::cout << "--------------------------\n";

    {
        char str[]="Zeyad";
        String t1{str};

        String &&t2{std::move(t1)};

        t2.display();
    }

    std::cout << "--------------------------\n";
    {
        char str[]="Zeyad";
        String t1{str};

        // Copy constructor is called if no move constructor is given !!??
        String t2 = std::move(t1);

        // t1.display();
        t2.display();
    }

    std::cout << "--------------------------\n";

    {
        char str[]="Zeyad";
        
        String t1{str};

        // t2 will replace t1
        String &&t2 {std::move(t1)};

        String t3{str};

        // t4 will take ownership from name
        String t4{std::move(t3)};

    }

    std::cout << "--------------------------\n";

    return 0;
}
