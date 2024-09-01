#include <iostream>
#include <string>

// Base case: when there are no more arguments
void print() 
{
    std::cout << std::endl;
}

// Variadic template function
template<typename T, typename... Args>
void print(T first, Args... args) 
{
    std::cout << first << " ";
    print(args...);  
}

// Sum function using variadic templates
template<typename T>
T sum(T t) 
{
    return t;
}

template<typename T, typename... Args>
T sum(T first, Args... args) 
{
    return first + sum(args...);
}

int main() 
{
    // Example usage of variadic print function
    print("Hello", 42, 3.14, "World");

    // Example usage of variadic sum function
    int result1 = sum(1, 2, 3, 4, 5);
    double result2 = sum(1.1, 2.2, 3.3);

    std::cout << "Sum 1: " << result1 << std::endl;
    std::cout << "Sum 2: " << result2 << std::endl;

    return 0;
}