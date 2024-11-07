#include <iostream>

// Class template with a default template argument
template <typename T = int> 
class MyClass {
public:
    T value;

    MyClass(T val) : value(val) {}

    void display() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    // Using the default template argument (int)
    MyClass<> obj1(10);
    obj1.display();  // Output: Value: 10

    // Specifying a different template argument (double)
    MyClass<double> obj2(5.5);
    obj2.display();  // Output: Value: 5.5

    return 0;
}
