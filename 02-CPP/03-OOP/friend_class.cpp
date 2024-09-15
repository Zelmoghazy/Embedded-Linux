#include <iostream>
#include <ostream>

// Forward declaration of class B
class B;

class A {
private:
    int aValue;

public:
    A(int value) : aValue(value) {}

    // Declare B as a friend class -> give permission to access private members
    friend class B;
};

class B {
public:
    void showValueFromA(const A& aObj) {
        // Accessing private member of A
        std::cout << "Value from A: " << aObj.aValue << std::endl;
    }
};

class C {
    private:
        int cValue;
        // friend function
        friend void fun();
};

class D {
    int Dval1;
    int Dval2;
    int Dval3;
    int Dval4;

    public :
        D(int val1,int val2, int val3, int val4) : Dval1(val1), Dval2(val2),Dval3(val3),Dval4(val4){}

        // Practoical use Implementation of the friend function
        friend std::ostream& operator<<(std::ostream& os, const D& obj) {
            os << "Dval1: " << obj.Dval1 << ", ";
            os << "Dval2: " << obj.Dval2 << ", ";
            os << "Dval3: " << obj.Dval3 << ", ";
            os << "Dval4: " << obj.Dval4;
        return os;
    }
};

// can access class private members
void fun()
{
    C var;
    var.cValue = 15;
    std::cout << var.cValue<<std::endl;
}


int main() {
    A a(42);
    B b;

    // B can access the private member of A
    b.showValueFromA(a);

    fun();

    D dvar(25,26,27,28);
    std::cout << dvar << std::endl;

    return 0;
}
