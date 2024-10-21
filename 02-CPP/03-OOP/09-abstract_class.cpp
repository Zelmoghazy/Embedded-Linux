#include <iostream>

/*
    Abstract class
        - abstract class in C++ is a class that contains at least one pure virtual function
        - which makes the class not instantiable
*/ 

class Animal {
public:
    virtual void makeSound() const = 0;

    virtual void eat() const {
        std::cout << "This animal is eating." << std::endl;
    }

    virtual ~Animal() = default;
};

// Derived class Dog
class Dog : public Animal {
public:
    // Implement the pure virtual function
    void makeSound() const override {
        std::cout << "Woof! Woof!" << std::endl;
    }

    // Override the eat function
    void eat() const override {
        std::cout << "The dog is eating dog food." << std::endl;
    }
};

// Derived class Cat
class Cat : public Animal {
public:
    // Implement the pure virtual function
    void makeSound() const override {
        std::cout << "Meow! Meow!" << std::endl;
    }

    // // Override the eat function
    // void eat() const override {
    //     std::cout << "The cat is eating cat food." << std::endl;
    // }
};

int main() {
    // Create objects of derived classes
    Dog myDog;
    Cat myCat;

    // Use the objects
    myDog.makeSound();  // Outputs: Woof! Woof!
    myDog.eat();        // Outputs: The dog is eating dog food.

    myCat.makeSound();  // Outputs: Meow! Meow!
    myCat.eat();        // Outputs: The cat is eating cat food.

    return 0;
}
