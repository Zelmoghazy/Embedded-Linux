#include <iostream>
#include <iterator>
#include <string_view>


int global_var = 200;
const int const_global_var = 10;

// since c++11 -> single return statement 
constexpr int fun()
{
    return 5;
}

/*
    since c++17 -> all will be evaluated at compile time.
        - function's body cannot contaon try-catch or static vars
        - arguments should be constexpr or literals (or it will be normal)
*/ 
constexpr int fun2()
{
    /* 
        note that if the receiving end is not constexpr this wont produce 
        an error but the function would become a normal function
     */

    // std::cout << "Hello";  // error not constexpr

    int sum = 0;
    for (int i = 0; i < 50; i++) {
        if (i%20==9){
            sum += i;
        }
    }
    return sum+fun(); // can call other constexpr functions
}

/* calculated at compile time */
constexpr double convert(double value, std::string_view from_unit, std::string_view to_unit) {
    // Length 
    if (from_unit == "m" && to_unit == "km") return value / 1000.0;
    if (from_unit == "km" && to_unit == "m") return value * 1000.0;
    if (from_unit == "m" && to_unit == "mi") return value / 1609.34;
    if (from_unit == "mi" && to_unit == "m") return value * 1609.34;
    if (from_unit == "km" && to_unit == "mi") return value / 1.60934;
    if (from_unit == "mi" && to_unit == "km") return value * 1.60934;

    // Temperature 
    if (from_unit == "C" && to_unit == "F") return (value * 9.0 / 5.0) + 32.0;
    if (from_unit == "F" && to_unit == "C") return (value - 32.0) * 5.0 / 9.0;
    if (from_unit == "C" && to_unit == "K") return value + 273.15;
    if (from_unit == "K" && to_unit == "C") return value - 273.15;
    if (from_unit == "F" && to_unit == "K") return (value - 32.0) * 5.0 / 9.0 + 273.15;
    if (from_unit == "K" && to_unit == "F") return (value - 273.15) * 9.0 / 5.0 + 32.0;

    return value;
}

struct Example {
    int member = 0;

    // const functions doesnt modify the object equivalent to foo(const *this)
    void foo() const {
        // member = 15;  // Error!
    }
};

void func(int &a)
{
    a++;
}

void const_func(int const &a)
{
    std::cout << a << std::endl;
}


class Circle {
public:
    /* 
        Any constexpr member variable must be static.
        as Member variables of functions are not available
        until an instance of that class is created
        and constepxr means 'This is available at compile time'.
     */
    static constexpr double pi = 3.14159;  // constexpr static member

    constexpr Circle(double radius) : radius_(radius) {}

    constexpr double area() const {  // constexpr member function
        return pi * radius_ * radius_;
    }

private:
    double radius_;
};


int main (void)
{
    int x = global_var;
    int var = const_global_var;

    /* -------------------------------------- */
    int a = 0;
    int const b = 0;
    
    func(a);
    // func(b);    // error will lose const qualifier

    const_func(a);  // ok
    const_func(b);  // ok


    /* -------------------------------------- */

    // can be used as size in static arrays
    int arr[const_global_var] = {0};

    /* -------------------------------------- */

    // can be use as case value in switch statements
    switch(var)
    {
        case const_global_var:
            std::cout<<"global const\n";
            break;
        default:
            break;   
    }

    /* -------------------------------------- */

    // int *ptr = &global_var;                       // error
    int *ptr2 = const_cast<int*>(&const_global_var); // allowed

    /* -------------------------------------- */

    const int const_var1 = 10;       // allowed
    int const const_var2 = 10;       // same thing but follows the rule  <T const>

    // const_var1 = 15;             // error

    std::cout<<"const : " << const_var1 << '\n';
    /* -------------------------------------- */

    constexpr int const_expr1 = 10;  // allowed

    std::cout<<"constexpr : " << const_expr1 << '\n';

    /* -------------------------------------- */
    int num; 
    std::cin >> num;
    const int const_var3 = num;          // allowed
    // constexpr int const_expr2 = num;  // error must be initialized by constant
    std::cout << const_var3 << std::endl;

    /* -------------------------------------- */

    /* Evaluated at compile time */
    int constexpr const_expr_var1 = fun();
    int constexpr const_expr_var2 = fun2();

    std::cout<< const_expr_var1 << std::endl;
    std::cout<< const_expr_var2 << std::endl;


    return 0;
}


