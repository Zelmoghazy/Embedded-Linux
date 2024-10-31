#include <cmath>
#include <iostream>

class Complex {
public:
    double real, imag;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Overload the + operator
    /* 
        operator definition is implemented as a regular method
        with a special name given operator @ -> operator@() 
     */
    Complex operator + (const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator + (double other) const {
        return Complex(real + other, imag);
    }

    // Overload the - operator
    Complex operator - (const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload the * operator
    Complex operator * (const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    // Overload the / operator
    Complex operator / (const Complex& other) const {
        double denom = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denom, 
                       (imag * other.real - real * other.imag) / denom);
    }

    // Overload the == operator
    bool operator == (const Complex& other) const {
        return (real == other.real && imag == other.imag);
    }

    // Overload the << operator (stream insertion)
    friend std::ostream& operator << (std::ostream& os, const Complex& c) {
        os << c.real;
        if (c.imag >= 0) os << "+";
        os << c.imag << "i";
        return os;
    }

    // Overload the [] operator (subscript operator)
    double& operator [] (int index) {
        if (index == 0)
            return real; // Access the real part
        else if (index == 1)
            return imag; // Access the imaginary part
        else
            throw std::out_of_range("Index out of range");
    }

    // Overload the -> operator (arrow operator)
    Complex* operator -> () {
        return this; // Return the pointer to the current object
    }

    // Function to get the magnitude of the complex number
    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }
};

Complex operator+(float a, const Complex &obj)
{
    return Complex(a + obj.real, obj.imag);
}


int main(void) 
{
    Complex c1{3.0, 4.0}, c2{1.0, 2.0};

    Complex sum = c1 + c2;
    std::cout << "Sum: "  << sum    << std::endl;

    // Equivalent to 
    sum = c1.operator+(c2);
    std::cout << "Sum: "  << sum    << std::endl;

    Complex diff = c1 - c2;
    Complex prod = c1 * c2;
    Complex quot = c1 / c2;

    std::cout << "c1 = "  << c1     << std::endl;
    std::cout << "c2 = "  << c2     << std::endl;
    std::cout << "Sum: "  << sum    << std::endl;
    std::cout << "Diff: " << diff   << std::endl;
    std::cout << "Prod: " << prod   << std::endl;
    std::cout << "Quot: " << quot   << std::endl;
    
    std::cout << "Are c1 and c2 equal? " << (c1 == c2 ? "Yes" : "No") << std::endl;

    // Subscript operator []
    std::cout << "Real part of c1: " << c1[0] << std::endl;
    std::cout << "Imaginary part of c1: " << c1[1] << std::endl;

    // Modifying via subscript operator
    c1[0] = 5.0;
    c1[1] = 6.0;
    std::cout << "Modified c1 = " << c1 << std::endl;

    // Arrow operator ->
    std::cout << "Magnitude of c1 (using -> operator): " << c1->magnitude() << std::endl;


    Complex c3 = c1 + 4.0f;
    std::cout << "c3 = " << c3 << std::endl;

    Complex c4 = 4.0f + c1;
    std::cout << "c4 = " << c4 << std::endl;

    return 0;
}
