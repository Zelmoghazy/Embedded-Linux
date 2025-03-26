#include <iostream>
#include <ostream>
#include <string>

// Data members in class are private by default
class Car 
{
    // Private data members
    private:
        std::string brand;
        std::string model;
        int year;
    // Public data members
    public:
        std::string color;
        int speed{0};               // define default value at declaration
        const int power = 5000;
        // int &number;             // reference must be in initializer
        // const int constant;      // constant must be in initializer list

        // Constructor take the name of the class and have no return type 
        // if no constructor is added the compile generates a default empty constructor Car(){}
        // Car(){
        //     std::cout << "default constructor \n";
        // }

        Car()=delete;   // cannot create a default constructor compiler error if called ,i.e Car c{}; -> compiler error

        // Destructor take ~ followed by the name of the class and have no return type
        ~Car(){}
        
        Car(int year) : year(year){}

        /* 
            explicit denotes preventing implicit conversions
            class String {
                public:
                    String(int n); // allocate n bytes to the String object
                    String(const char *p); // initializes object with char *p
            };
            String mystring = 'x';

            The character 'x' will be implicitly converted to int and then the String(int) constructor will be called which is not what the user required and would lead to very subtle bugs.
         */
        explicit Car(std::string model) : model(model)
        {

        }

        // delegation constructor -> calls another constructor
        Car(std::string brand,std::string model) : Car(brand,model,0,"BLACK",50)
        {

        }
        // Paramertized Constructor
        Car(std::string b, std::string m, int y, std::string c, int s) 
            : brand(b), model(m), year(y), color(c), speed(s) {}        // Initializer list
        
        // Methods wont be added to .text section if not used
        // Public method to display car details
        void displayDetails() 
        {
            std::cout << "Brand: "  << brand    << std::endl;
            std::cout << "Model: "  << model    << std::endl;
            std::cout << "Year: "   << year     << std::endl;
            std::cout << "Color: "  << color    << std::endl;
            std::cout << "Speed: "  << speed    << " km/h" << std::endl;
        }

        std::string get_car_brand() const {
            // you cannot modify member withing a constant member function
            // unless the member is mutable or static
            return this->brand;
        }
        std::string get_car_model(){
            return this->model;
        }

        void accelerate(int increase) {
            speed += increase;
            std::cout << "The car accelerates by " << increase << " km/h." << std::endl;
        }

        void brake(int decrease) {
            if (speed - decrease < 0) {
                speed = 0;
            } else {
                speed -= decrease;
            }
            std::cout << "The car slows down by " << decrease << " km/h." << std::endl;
        }

        void beep();
        void window_up() = delete;
};


// Will be added to .text section even if not used
void Car::beep(void) 
{
    std::cout << "beep\n";
}

int main(void) 
{
    // ways to call the constructor
    Car c1{"Dodge","RAM"};
    Car c2 = {"Dodge","RAM"};
    Car c3("Dodge","RAM");
    /* Note that using parenthesis () is not recommended to be used 
        - Car c{}; -> calls default constructor
        - Car c(); -> declares a function !!!
    */

    // Creating an object of the Car class
    Car myCar{"Toyota", "Corolla", 2020, "Red", 120};

    // Accessing public data members
    std::cout << "Car color: " << myCar.color << std::endl;
    std::cout << "Car speed: " << myCar.speed << " km/h" << std::endl;

    // Using public methods
    myCar.displayDetails();
    myCar.accelerate(30);
    myCar.brake(50);
    myCar.beep();

    // Car car2{}; // error call to deleted constructor

    Car car3 {"Nissan","GTR"};
    car3.displayDetails();
    // car3.window_up(); // Error deleted function
    std::cout << car3.get_car_brand() << std::endl;

    const Car car4 {"Porsche","970"};
    car4.get_car_brand();       // allowed
    // car4.get_car_model();    // error const instace cann only call const member functions
    return 0;
}
