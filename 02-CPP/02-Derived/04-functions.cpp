
#include <iostream>
#include  <string.h>
#include <random>


// Default Parameters
void printf_default(std::string message = "Hello World")
{
    std::cout << message << std::endl;
}

// Error : after a parameter with a default argument, all subsequent parameters must have a default argument supplied in this or a previous declaration from the same scope
// void printf_default(std::string message = "Hello World", int x)
// {
//     std::cout << message << std::endl;
// }


/* ----------------------------------------- */

int get_random_int(void)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distr(1, 100);

    return distr(gen);
}

// Function Overloading
int mul(int a = get_random_int(), int b = get_random_int())
{
    std::cout << "mul(int,int)" << std::endl;
    return a*b;
}

float mul(float a, float b)
{
    std::cout << "mul(float,float)" << std::endl;
    return a*b;
}

/* ----------------------------------------- */

int main(void)
{
    printf_default();
    printf_default("Testing");
    
    std::cout<<mul()<<std::endl;
    std::cout<<mul(5,6)<<std::endl;
    std::cout<<mul(5.0f,6.0f)<<std::endl;
    // std::cout<<mul(5,6.0f)<<std::endl; // Error ambiguous
}