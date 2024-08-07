#include <iostream>

int main(void)
{
    // Switch case can use integer constant in case label in cpp -> error in pure c
    int variable = 10;
    const int const_val = 10;

    switch (variable) 
    {
        case const_val:
            std::cout << "The Value is 10" << '\n';
            break;
        default:
            std::cout << "The Value is not 10" << '\n';
            break;
    }
}