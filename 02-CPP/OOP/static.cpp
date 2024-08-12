#include <iostream>
#include <ostream>
#include <vector>

class Example {
private:
    // a static data member is not related to an instance but related to the class
    static int count;  // Static data member
public:
    // you can access the static data member using the class name or the instance name
    static int var;
    static const int MAX = 5; // special initialization must be integral or enumeration type -> compiler replace it with its value 
    static const int MIN;
    // static const float PI = 3.14f; // Error must be of integral or enumeration type to be defined here
    static const float PI ; 
    // static const int temp; // Error cannot be defined in constructor
    int temp;

public:
    // creating any instance of Example class will increase the counter
    Example() {
        count++;
    }

    // Static member function to get the count of objects
    // Static functions is related to class not an instance
    static int getCount() {
        return count;
    }

    // Static member function to reset the count
    static void resetCount() {
        count = 0;
    }

    // Error :  Cannot use a non-static member inside a static function
    // static void static_fun() {
    //     temp = 15;
    // }
};

// Definition of static data member should be outside the class
int Example::count = 0;     // .bss section -> dont use static here outside the class
int Example::var = 5;       // .data section
const int Example::MIN = 0; 
const float Example::PI = 3.14; 

const int temp1 = 15;        // Internal Linkage 
extern const int temp2 = 15; // External Linkage 

void get_by_ref(const int &a)
{
    std::cout << &a << std::endl;
}


int main()
{
    Example obj1;
    Example obj2;

    // Display the number of objects created
    std::cout << "Number of objects created: " << Example::getCount() << std::endl;  
    std::cout << "Number of objects created: " << obj1.getCount() << std::endl;  
    std::cout << "Number of objects created: " << obj2.getCount() << std::endl;  

    // Reset the count
    Example::resetCount();

    std::cout << "Count after reset: " << Example::getCount() << std::endl;  

    std::vector<Example> v1(5);

    std::cout << "Number of objects created: " << Example::getCount() << std::endl;  


    std::cout << "Static var : " << Example::var << std::endl;
    std::cout << "Static var : " << obj1.var << std::endl;
    std::cout << "Static var : " << obj2.var << std::endl;
    std::cout << "Static var : " << obj2.PI << std::endl;

    // get_by_ref(Example::MAX); // linker error as used special initialization will replaced by its value
    get_by_ref(Example::MIN); // allowed as it saved in .rodata
    return 0;
}
