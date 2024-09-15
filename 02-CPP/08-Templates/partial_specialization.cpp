#include <iostream>

// Primary template
template<typename T, typename U>
class MyClass {
public:
    void print() {
        std::cout << "General template" << std::endl;
    }
};

// Partial specialization for when the second type is int
template<typename T>
class MyClass<T, int> {
public:
    void print() {
        std::cout << "Partial specialization: second type is int" << std::endl;
    }
};

// Partial specialization for when both types are the same
template<typename T>
class MyClass<T, T> {
public:
    void print() {
        std::cout << "Partial specialization: both types are the same" << std::endl;
    }
};

int main() {
    MyClass<double, float> obj1;
    MyClass<char, int> obj2;
    MyClass<float, float> obj3;

    obj1.print();  // Output: General template
    obj2.print();  // Output: Partial specialization: second type is int
    obj3.print();  // Output: Partial specialization: both types are the same

    return 0;
}