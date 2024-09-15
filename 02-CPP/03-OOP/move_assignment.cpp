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

        // copy assignment 
        String &operator=(const String &obj)
        {
            std::cout << "copy assignment\n";
            // Handling self assignment
            if(this == &obj)
            {
                return *this;
            }

            delete[] this->str;
            this->size = obj.size;

            this->str = new char[size+1];
            strcpy(this->str, obj.str) ;
            
            return *this;
        }

        // move assignment 
        String &operator=(String &&obj)
        {
            std::cout << "move assignment\n";
            // Handling self assignment
            if(this == &obj)
            {
                return *this;
            }

            delete[] this->str;
            
            this->str = obj.str;
            this->size = obj.size;

            obj.size = 0;
            obj.str = nullptr;

            return *this;
        }

        void display()
        {
            std::cout << str << ' ' << size << ' ' << this << std::endl;
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
    
    // copy assignment
    s1 = s2; 

    // move assignment
    s1 = std::move(s2);

    s1.display();
    s2.display();

    std::cout << "Reached!" << std::endl;

    return 0;
}
