#include <iostream>
#include <any>
#include <string>
#include <vector>

// Function to print the type and value of an any object
void print_any(const std::any& value) {
    try {
        if (!value.has_value()) {
            std::cout << "Empty any object" << std::endl;
        }
        else if (value.type() == typeid(int)) {
            std::cout << "Integer: " << std::any_cast<int>(value) << std::endl;
        }
        else if (value.type() == typeid(std::string)) {
            std::cout << "String: " << std::any_cast<std::string>(value) << std::endl;
        }
        else if (value.type() == typeid(double)) {
            std::cout << "Double: " << std::any_cast<double>(value) << std::endl;
        }
        else if (value.type() == typeid(std::vector<int>)) {
            const auto& vec = std::any_cast<std::vector<int>>(value);
            std::cout << "Vector<int>: ";
            for (int num : vec) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
        else {
            std::cout << "Unknown type with type name: " << value.type().name() << std::endl;
        }
    }
    catch (const std::bad_any_cast& e) {
        std::cout << "Bad any_cast: " << e.what() << std::endl;
    }
}

// Function that returns different types in a std::any
std::any create_dynamic_object(int type_selector) {
    switch (type_selector) {
        case 0: return 42;  // Integer
        case 1: return std::string("Hello, std::any!");  // String
        case 2: return 3.14159;  // Double
        case 3: return std::vector<int>{1, 2, 3, 4, 5};  // Vector
        default: return {};  // Empty any
    }
}

int main() {
    // Demonstrating basic std::any usage
    std::cout << "Basic std::any Usage:" << std::endl;
    
    // Creating any objects with different types
    std::any int_any = 100;
    std::any string_any = std::string("C++ is awesome");
    std::any double_any = 3.14;
    std::any vector_any = std::vector<int>{10, 20, 30};
    
    // Printing the values
    print_any(int_any);
    print_any(string_any);
    print_any(double_any);
    print_any(vector_any);
    
    // Demonstrating dynamic object creation
    std::cout << "\nDynamic Object Creation:" << std::endl;
    for (int i = 0; i <= 4; ++i) {
        std::any dynamic_obj = create_dynamic_object(i);
        print_any(dynamic_obj);
    }
    
    // Checking and modifying any objects
    std::cout << "\nChecking and Modifying:" << std::endl;
    
    std::any modifiable_any;
    
    // Checking if the any object has a value
    std::cout << "Initial any object has value: " 
              << (modifiable_any.has_value() ? "Yes" : "No") << std::endl;
    
    // Assigning a value
    modifiable_any = 256;
    std::cout << "After assigning an int: ";
    print_any(modifiable_any);
    
    // Reassigning to a different type
    modifiable_any = std::string("Changing type");
    std::cout << "After changing to a string: ";
    print_any(modifiable_any);
    
    // Safe type checking before casting
    std::any unsafe_any = 42;
    if (unsafe_any.type() == typeid(int)) {
        std::cout << "\nSafe cast: " 
                  << std::any_cast<int>(unsafe_any) << std::endl;
    }
    
    return 0;
}