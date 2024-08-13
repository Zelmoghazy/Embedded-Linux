#include <algorithm>
#include <iostream>
#include <iterator>
#include <locale>
#include <ostream>
#include <string>
#include <vector>


class LCD
{
    public:
        std::string msg;
        int cursor;

        // default constructor
        LCD() = default;

        // explicit prevents any implicit conversions
        explicit LCD(std::string ms) : msg(ms){};

        LCD(std::string ms, int curs) : msg(ms),cursor(curs){};

        void display(){
            std::cout << msg << std::endl;
        }

        // += operator overloading
        // datatype operator op (argument-list) {body}
        LCD &operator+=(const std::string& message){
            this->msg += message;
            return *this;
        }

        // << operator overloading
        friend std::ostream& operator<<(std::ostream& os, const LCD& obj) {
            os << "Message: " << obj.msg <<" Cursor: "<<  obj.cursor << std::endl;
            return os;
        }

        bool operator>(const LCD &lcd);

        bool operator<(const LCD &lcd);

        // Pre-Increment
        LCD& operator++(){
            std::cout << "Pre-Increment" << std::endl;
            this->cursor++;
            return *this;
        }
        // Post increment
        int operator++(int)
        {
            std::cout << "Post-Increment" << std::endl;
            int temp = this->cursor;
            this->cursor++;
            return temp;
        }

        LCD& operator=(int x){
            this->cursor = x;
            return *this;
        }

        // functor
        void operator()(void){
            std::cout << "Functor !!" <<std::endl;
        }

        // operator conversion
        operator std::string(){
            return msg;
        } 
};

bool LCD::operator<(const LCD &lcd)
{
    return this->msg < lcd.msg;
}

bool LCD::operator>(const LCD &lcd)
{
    return this->msg > lcd.msg;
}

std::string operator+(const LCD &lcd, const std::string &message)
{
    return lcd.msg + message + '\n';
}

int main(void)
{
    LCD lcd1{"Hello world"};
    LCD lcd2{"Hello world"};

    lcd1.display();
    lcd2.display();

    std::cout << lcd1;
    std::cout << lcd2;

    lcd1 += " from lcd 1";
    lcd2 += " from lcd 2";

    std::cout << lcd1;
    std::cout << lcd2;

    std::string message = " Operator overloading !!";
    std::string res = lcd1 + message; 

    std::cout << res;

    std::cout << lcd1.cursor << std::endl;
    ++lcd1;
    std::cout << lcd1.cursor << std::endl;
    lcd1++;
    std::cout << lcd1.cursor << std::endl;

    int x = 100;
    ++x = 200;
    std::cout << x << std::endl;

    ++lcd1 = 11;
    std::cout << lcd1.cursor << std::endl;

    std::vector<LCD> vec{{"test1",5},{"test2",7}, {"test3",4}, {"test5",7}, {"test6",5}};

    std::sort(vec.begin(),vec.end());
    std::copy(vec.begin(),vec.end(),std::ostream_iterator<LCD>(std::cout,"\n"));


    // Functor
    lcd1();

    // temporary object
    std::cout << LCD{"Temporary",55} <<std::endl;


    // operator conversion
    LCD lcd3{"Test operator conversion",0};
    std::string test = " Test: ";
    test += lcd3;
    std::cout<<test<<std::endl;
    
    return 0;
}