#include <iostream>
#include <tuple>
#include <string>


// Function that returns a tuple
std::tuple<int, double, std::string> getPersonInfo() {
    return std::make_tuple(25, 175.5, "John Doe");
}

int main(void) 
{
    // Create a tuple with different types
    std::tuple<int, double, std::string> myTuple(1, 3.14, "Hello, World!");

    // Access elements using std::get
    int myInt               = std::get<0>(myTuple);
    double myDouble         = std::get<1>(myTuple);
    std::string myString    = std::get<2>(myTuple);

    // Print the elements
    std::cout << "Integer: " << myInt    << std::endl;
    std::cout << "Double: "  << myDouble << std::endl;
    std::cout << "String: "  << myString << std::endl;


    /* -------------------------------------------------------------------- */

    int age;
    double height;
    std::string name;

    std::tie(age, height, name) = getPersonInfo();

    // Output the unpacked values
    std::cout << "Age: "    << age      << std::endl;
    std::cout << "Height: " << height   << " cm" << std::endl;
    std::cout << "Name: "   << name     << std::endl;

    return 0;
}
