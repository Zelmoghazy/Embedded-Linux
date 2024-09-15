/* 
    dynamic_cast is primarily used for safely downcasting pointers or references of a base class to a derived class.
 */

#include <iostream>

class Base {
public:
    virtual ~Base() {} // Virtual destructor for proper cleanup
};

class Derived : public Base {
public:
    void display() {
        std::cout << "Derived class method called!" << std::endl;
    }
};

class Unrelated {};

int main(void) 
{
    Base* basePtr = new Derived(); // Upcasting
    
    // returns nullptr if casting is not allowed
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

    if (derivedPtr != nullptr) {
        derivedPtr->display(); // Safely downcasted to Derived
    } else {
        std::cout << "Failed to cast Base* to Derived*." << std::endl;
    }

    // Trying to cast to an unrelated type
    Unrelated* unrelatedPtr = dynamic_cast<Unrelated*>(basePtr);
    if (unrelatedPtr == nullptr) {
        std::cout << "Failed to cast Base* to Unrelated* (as expected)." << std::endl;
    }

    delete basePtr; // Clean up
    return 0;
}

