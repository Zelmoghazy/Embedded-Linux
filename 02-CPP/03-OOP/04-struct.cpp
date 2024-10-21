#include <iostream>
#include <string>


// Data members in struct are public by default
struct Person {
    std::string name;
    int age;

    /* Default Constructor */
    Person(){
        name = "default";
        age = 0;
        std::cout << "Default Constructor is called\n"; 
    }

    Person(std::string name, int age){
        this->name = name;
        this->age = age;
    }

    /* Destructor */
    ~Person(){
        name = "default";
        age = 0;
        std::cout << "Destructor is called\n"; 
    }

    void setter(std::string name, int age){
        this->name = name;
        this->age = age;
    }

    std::string get_name(void){
        return name;
    }

    void displayInfo() {
        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
    }
};

/* 
objects are initialized using the constructor method. So the memory is allocated in bss, then during startup the constructor is called to fill in the contents.
 */
Person global_person = {"Jane Smith", 28};

int main() {
    // Creating an instance of Person
    Person person1;
    
    // Assigning values to the members
    person1.name = "John Doe";
    person1.age = 30;

    std::cout << "Person 1 Info:" << std::endl;
    person1.displayInfo();

    Person person2 = {"Jane Smith", 28};

    std::cout << "\nPerson 2 Info:" << std::endl;
    person2.displayInfo();

    person2.setter("Zeyad", 23);
    person2.displayInfo();

    {
        Person person3;
        person3.displayInfo();
    }

    std::cout << "Done\n"; 

    return 0;
}
