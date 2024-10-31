#include <iostream>


class Binary_Function{
    public:
        virtual double operator() (double a, double b) = 0;
};

double binary_op(double a, double b, Binary_Function &func)
{
    return func(a,b);
}

/* We can extern the binary functions as much as we like */
class Add : public Binary_Function{
public:
    double operator()(double a, double b) override {
        return a + b;
        
    }
};

class Multiply : public Binary_Function{
public:
    double operator()(double a, double b) override {
        return a * b;
    }
};


int main(void) 
{
    Add add_func;
    Multiply multiply_func;
    
    double a = 5.0;
    double b = 10.0;

    double c = binary_op(a, b, add_func);
    std::cout << c << std::endl;

    double d = binary_op(a, b, multiply_func);
    std::cout << d << std::endl;

    return 0;
}
