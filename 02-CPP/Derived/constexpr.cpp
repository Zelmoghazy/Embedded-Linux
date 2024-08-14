#include <iostream>
#include <iterator>


int global_var = 200;
const int const_global_var = 10;

// since c++11 -> single return statement 
constexpr int fun()
{
    return 5;
}

// since c++17 -> all will be evaluated at compile time. 
constexpr int fun2()
{
    // std::cout << "Hello";  // error not constexpr, note that if the receiving end is not constexpr this wont produce an error but the function would become a normal function
    int sum = 0;
    for (int i = 0; i < 50; i++) {
        if (i%20==9){
            sum += i;
        }
    }
    return sum+fun(); // can call other constexpr functions
}



int main (void)
{
    int x = global_var;
    int var = const_global_var;

    int arr[const_global_var] = {0};
    switch(var){
        case const_global_var:
            std::cout<<"global const\n";
            break;
        default:
            break;   
    }
    // int *ptr = &global_var; //error

    int *ptr2 = const_cast<int*>(&const_global_var); // allowed


    /* -------------------------------------- */

    const int const_var1 = 10;       // allowed
    constexpr int const_expr1 = 10;  // allowed

    std::cout<<"const : " << const_var1 << '\n';
    std::cout<<"constexpr : " << const_expr1 << '\n';

    int num; 
    std::cin >> num;
    const int const_var2 = num;      // allowed
    // constexpr int const_expr2 = num;  // error must be initialized by constant
    std::cout << const_var2 << std::endl;

    /* -------------------------------------- */

    int constexpr const_expr_var1 = fun();
    int constexpr const_expr_var2 = fun2();

    std::cout<< const_expr_var1 << std::endl;
    std::cout<< const_expr_var2 << std::endl;


    return 0;
}


