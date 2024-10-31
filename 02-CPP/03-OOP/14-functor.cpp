#include <iostream>

/*
    Functors are a way to dynamically construct functions
    by using objects of a class that implements the () operator
 */

class MultiplyBy {
public:
    MultiplyBy(int factor) : factor_(factor) {}

    int operator()(int value) const {
        return value * factor_;
    }

private:
    int factor_;
};


int main(void) 
{
    MultiplyBy multiplyBy5{5};
    int result = multiplyBy5(10);

    int res2 = MultiplyBy{5}(10);

    std::cout << "10 multiplied by 5 is: " << result << std::endl;
    std::cout << "3 multiplied by 5 is: " << multiplyBy5(3) << std::endl;

    std::cout << "10 multiplied by 5 is: " << res2 << std::endl;

    return 0;
}
