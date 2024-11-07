#include <cassert>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <ostream>


/* 

    copy constructors and copy assignment operators 
        give you control over what it means to copy objects

    Rule of Three :
    a type must have all three if one is needed
    1- copy constructor
    2- copy assignment
    3- destructor

 */

class String{
    private:
        char* str;
        uint64_t size;
    
    public:
        String(const char* str){
            size = strlen(str);
            this->str = new char[size+1];
            strcpy(this->str, str);
        }
        ~String(){
            delete[] (this->str);
            this->str = nullptr;
        }
        String (const String &obj){
            std::cout << "Copy Constructor\n";
            size = obj.size + 1;
            str = new char[size]; // allocate in heap
            strcpy(str,obj.str);
        }

        String &operator=(const String &obj)
        {
            std::cout << "assignment operator\n";
            // Handling self assignment
            if(this == &obj)
            {
                return *this;
            }

            delete[] this->str;
            this->str = new char[obj.size+1];
            strcpy(this->str, obj.str) ;
            
            return *this;
        }

        void display()
        {
            std::cout << str << ' ' << size << std::endl;
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
    String s1("Hello");
    String s2("world");

    s1 = s2;

    s1.display();
    s2.display();

    // Problem !!
    // first we delete then we take garbage
    // and add it back -> wrong
    s2 = s2;
    s1.display();
    s2.display();

    return 0;
}
