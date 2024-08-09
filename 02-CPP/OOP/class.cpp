#include <iostream>
#include <string>

class Car {
private:
    // Private data members
    std::string brand;
    std::string model;
    int year;

public:
    // Public data members
    std::string color;
    int speed;

    // Constructor
    Car(std::string b, std::string m, int y, std::string c, int s) 
        : brand(b), model(m), year(y), color(c), speed(s) {}

    // Public method to display car details
    void displayDetails() {
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Year: " << year << std::endl;
        std::cout << "Color: " << color << std::endl;
        std::cout << "Speed: " << speed << " km/h" << std::endl;
    }

    // Public method to accelerate the car
    void accelerate(int increase) {
        speed += increase;
        std::cout << "The car accelerates by " << increase << " km/h." << std::endl;
    }

    // Public method to brake the car
    void brake(int decrease) {
        if (speed - decrease < 0) {
            speed = 0;
        } else {
            speed -= decrease;
        }
        std::cout << "The car slows down by " << decrease << " km/h." << std::endl;
    }
};

int main() {
    // Creating an object of the Car class
    Car myCar("Toyota", "Corolla", 2020, "Red", 120);

    // Accessing public data members
    std::cout << "Car color: " << myCar.color << std::endl;
    std::cout << "Car speed: " << myCar.speed << " km/h" << std::endl;

    // Using public methods
    myCar.displayDetails();
    myCar.accelerate(30);
    myCar.brake(50);

    return 0;
}
