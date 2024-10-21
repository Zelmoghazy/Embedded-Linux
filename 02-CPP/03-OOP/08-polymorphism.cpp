#include <iostream>
#include <ostream>


enum class Color {
    Red,
    Green,
    Blue,
    Yellow,
    Black,
    White,
    Orange
};

// Base class
class Shape {

public:
    Shape(){
        color = Color::Black;
    }

    Shape(Color color) : color(color){};

    /*
        Virtual function for polymorphism
        vtable => (dynamic binding)
        the most derived object is the one considered
    */
    virtual void draw() const {
        std::cout << "Drawing a generic shape\n";
    }

    // pure virtual funtion must be implemented in derived classes
    // marked by "=0" and makes their class abstract
    virtual void display_dim() const = 0; 

    // Virtual destructor to ensure proper cleanup
    virtual ~Shape() {}

private:
    Color color;
};

// Derived class 1
class Circle : public Shape {
public:
    using Shape::Shape;

    Circle(int r){
        this->radius = r;
    }

    /*
        when overriding a virtual method 
        the override keyword needs to be used
    */

    // Override the draw function
    void draw() const override {
        std::cout << "Drawing a circle\n";
    }

    void display_dim() const override {
        std::cout << "radius = " << radius << std::endl;;
    }

private:
    int radius = 0;
};

// Derived class 2
class Rectangle : public Shape {
public:
    using Shape::Shape;

    Rectangle(int l, int w){
        this->length = l;
        this->width = w;
    }
    // Override the draw function
    void draw() const override {
        std::cout << "Drawing a rectangle\n";
    }

    void display_dim() const override {
        std::cout << "length = " << length << " - " <<"width = " << width << std::endl;;
    }
private:
    int length = 0;
    int width  = 0;
};

// Derived class 3
class Triangle : public Shape {
public:
    using Shape::Shape;

    Triangle(int l1, int l2, int l3)
    {
        this->l1 = l1;
        this->l2 = l2;
        this->l3 = l3;
    }

    // Override the draw function
    void draw() const override {
        std::cout << "Drawing a triangle\n";
    }

    /*
        by declaring a virtual method final it cannot be overriden further 
     */
    void display_dim() const final {
        std::cout << "l1 = " << l1 <<  " - " << "l2 = " << l2 <<  " - " << "l3 = " << l3 << std::endl;;
    }
private:
    int l1 = 0;
    int l2 = 0;
    int l3 = 0;
};


void displayShape(const Shape& shape) 
{
    // Polymorphic call to draw the appropriate shape
    shape.draw();
    shape.display_dim();
}


int main(void) 
{
    Circle circle{5};
    Rectangle rectangle{5,10};
    Triangle triangle{5,12,13};

    displayShape(circle);     // Outputs: Drawing a circle
    displayShape(rectangle);  // Outputs: Drawing a rectangle
    displayShape(triangle);   // Outputs: Drawing a triangle

    Shape &s1 = circle;
    displayShape(s1);    

    Shape &s2 = rectangle;
    displayShape(s2);    

    Shape &s3 = triangle;
    displayShape(s3);    

    // Shape s;                // error : abstract class due to display_dim thus cannot be instantiated

    return 0;
}

