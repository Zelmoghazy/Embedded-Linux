#include <iostream>

// Forward declaration of class B
class B;

class A {
private:
    int aValue;

public:
    A(int value) : aValue(value) {}

    // Declare B as a friend class
    friend class B;
};

class B {
public:
    void showValueFromA(const A& aObj) {
        // Accessing private member of A
        std::cout << "Value from A: " << aObj.aValue << std::endl;
    }
};

int main() {
    A a(42);
    B b;

    // B can access the private member of A
    b.showValueFromA(a);

    return 0;
}
