#include <iostream>
#include <memory>

/*
    Interface class (Pure abstract class)
        - Has no data members and all of its methods are pure virtual
        - it is not allowed to create instance from the interface class
        - in the inherited class we must implement all pure virtual functions
*/

class Shape {
public:
    // Pure virtual function (no implementation)
    virtual void draw() const = 0;
    virtual double area() const = 0;

    // Virtual destructor
    virtual ~Shape() = default;
};

// Implementing class for a Circle
class Circle : public Shape {

public:
    Circle(double r) : radius(r) {}

    void draw() const override {
        std::cout << "Drawing a circle with radius: " << radius << std::endl;
    }

    double area() const override {
        return 3.14159 * radius * radius;
    }
    
private:
    double radius;
};

// Implementing class for a Rectangle
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void draw() const override {
        std::cout << "Drawing a rectangle with width: " << width << " and height: " << height << std::endl;
    }

    double area() const override {
        return width * height;
    }
};

int main() 
{
    // // Create shapes using interface pointer
    // std::unique_ptr<Shape> circle = std::make_unique<Circle>(5.0);
    // std::unique_ptr<Shape> rectangle = std::make_unique<Rectangle>(4.0, 6.0);

    // // Draw shapes and print area
    // circle->draw();
    // std::cout << "Area of circle: " << circle->area() << std::endl;

    // rectangle->draw();
    // std::cout << "Area of rectangle: " << rectangle->area() << std::endl;
    Circle circle{5};

    circle.draw();

    return 0;
}
