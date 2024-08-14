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
            delete this->str;
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
            if(this->str)
            {
                delete this->str;
                this->str = new char[obj.size+1];
                strcpy(this->str, obj.str) ;
            }
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

    return 0;
}
