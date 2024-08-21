#include <iostream>

class Base {
public:
    void publicMethod() {
        std::cout << "Base public method\n";
    }

protected:
    void protectedMethod() {
        std::cout << "Base protected method\n";
    }

private:
    void privateMethod() {
        std::cout << "Base private method\n";
    }
};

// Derived class with private inheritance
class Derived : private Base {
public:
    void accessBaseMethods() {
        publicMethod();        // Accessible: becomes private in Derived
        protectedMethod();     // Accessible: becomes private in Derived
        // privateMethod();    // Not accessible: remains private in Base
    }
};

class Derived2 : private Derived {
public:
    void accessBaseMethods() {
        // publicMethod();        // Not accessible
        // protectedMethod();     // Not accessible
        // privateMethod();       // Not accessible
    }
};



int main() {
    Derived d;
    d.accessBaseMethods();

    // d.publicMethod();      // Error: publicMethod is private in Derived
    // d.protectedMethod();   // Error: protectedMethod is private in Derived

    return 0;
}
