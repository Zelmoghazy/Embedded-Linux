#include <iostream>
#include <stdexcept>

/*
    The noexcept specifier in C++ is used to indicate that a function 
    is not expected to throw any exceptions which allows some optimizations.

    If you try to throw an exception in a function marked noexcept,
    the program will call std::terminate() and end immediately.
 */
void safeFunction() noexcept {
    std::cout << "This function is noexcept and won't throw exceptions." << std::endl;
}

void riskyFunction() {
    throw std::runtime_error("This function may throw exceptions.");
}

class CustomException : public std::exception 
{
public:
    // noexcept denotes that the function doesnt throw
    const char* what() const noexcept override {
        return "Custom exception occurred!";
    }
};

int divide(int numerator, int denominator) 
{
    if (denominator == 0) {
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    return numerator / denominator;
}

void innerFunction() 
{
    try 
    {
        // Simulate an error
        throw std::runtime_error("An error occurred in innerFunction.");
    } 
    catch (const std::exception& e)
    {
        std::cout << "Caught exception in innerFunction: " << e.what() << std::endl;
        std::cout << "Rethrowing exception to outer function ..." << std::endl;
        
        // Rethrow the exception to be caught by outerFunction
        throw; 
    }
}

void outerFunction() 
{
    try 
    {
        innerFunction();
    } 
    catch (const std::exception& e) 
    {
        std::cout << "Caught exception in outerFunction: " << e.what() << std::endl;
    }
}

int main(void) 
{
    int num   = 10;
    int denom = 0;

    try 
    {
        int result = divide(num, denom);
        std::cout << "Result: " << result << std::endl;
    } 
    catch (const std::invalid_argument& e) 
    {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    try
    {
        throw CustomException();
    }
    catch (const CustomException& e)
    {
        std::cerr << "Caught CustomException: " << e.what() << std::endl;
    }
    // Exception swallower
    catch (...) 
    {
        std::cerr << "Caught unknown exception" << std::endl;
    }

    try 
    {
        outerFunction();
    } 
    catch (const std::exception& e) 
    {
        std::cout << "Caught exception in main: " << e.what() << std::endl;
    }
    std::cout << "Program continues after exception handling." << std::endl;

    return 0;
}
