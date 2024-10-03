#include <iostream>
#include <ostream>

int var = 20;

int main(void)
{
    // declare variable inside if statement c++17
    // i is visible only inside the if statement
    // reducing its scope

    /* 
        Value val = GetValue();
        if (condition(val)) {
            // on success
        } else {
        // on false...
        }

        if (Value val = GetValue(); condition(val)) {
            // on success
        } else {
            // on false...
        }
        // val is visible only inside the if and else statements
    */
    if(int i = 15; i < var)
    {
        i = 13;
        std::cout << i <<std::endl;
    }else{
        i = 20;
        std::cout << i <<std::endl;
    }



    return 0;
}