#include <iostream>
#include <variant>
#include <string>
#include <vector>

// Visitor pattern for std::variant
struct Visitor {
    void operator()(int i) const {
        std::cout << "Integer: " << i << std::endl;
    }
    
    void operator()(double d) const {
        std::cout << "Double: " << d << std::endl;
    }
    
    void operator()(const std::string& s) const {
        std::cout << "String: " << s << std::endl;
    }
    
    void operator()(const std::vector<int>& vec) const {
        std::cout << "Vector: ";
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
};

// Function to print variant details
template <typename... Ts>
void print_variant(const std::variant<Ts...>& v) {
    std::visit(Visitor{}, v);
}

// Function to get the index of the current alternative
template <typename... Ts>
void print_variant_index(const std::variant<Ts...>& v) {
    std::cout << "Current alternative index: " 
              << v.index() << std::endl;
}

int main() {
    // Creating variants with different types
    std::cout << "Basic Variant Usage:" << std::endl;
    
    // Variant that can hold int, double, or string
    std::variant<int, double, std::string> mixed_variant;
    
    // Assigning different types
    mixed_variant = 42;
    print_variant(mixed_variant);
    print_variant_index(mixed_variant);
    
    mixed_variant = 3.14159;
    print_variant(mixed_variant);
    print_variant_index(mixed_variant);
    
    mixed_variant = "Hello, std::variant!";
    print_variant(mixed_variant);
    print_variant_index(mixed_variant);
    
    // Variant with more complex types
    std::cout << "\nComplex Variant:" << std::endl;
    std::variant<int, double, std::string, std::vector<int>> complex_variant;
    
    complex_variant = std::vector<int>{1, 2, 3, 4, 5};
    print_variant(complex_variant);
    print_variant_index(complex_variant);
    
    // Checking the type of a variant
    std::cout << "\nType Checking:" << std::endl;
    if (std::holds_alternative<int>(mixed_variant)) {
        std::cout << "Variant currently holds an int" << std::endl;
    }
    
    if (std::holds_alternative<std::string>(complex_variant)) {
        std::cout << "Complex variant holds a string" << std::endl;
    }
    
    // Getting a value from a variant
    std::cout << "\nRetrieving Values:" << std::endl;
    try {
        // Using std::get with type
        int int_value = std::get<int>(mixed_variant);
        std::cout << "Retrieved int value: " << int_value << std::endl;
        
        // Using std::get with index
        auto vec_value = std::get<3>(complex_variant);
        std::cout << "Retrieved vector value: ";
        for (int num : vec_value) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::bad_variant_access& e) {
        std::cout << "Error accessing variant: " << e.what() << std::endl;
    }
    
    // Using std::visit with lambda
    std::cout << "\nVisitor with Lambda:" << std::endl;
    std::visit([](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;
        if constexpr (std::is_same_v<T, int>) {
            std::cout << "Lambda: Integer value " << arg << std::endl;
        }
        else if constexpr (std::is_same_v<T, std::string>) {
            std::cout << "Lambda: String value " << arg << std::endl;
        }
        else if constexpr (std::is_same_v<T, std::vector<int>>) {
            std::cout << "Lambda: Vector value: ";
            for (int num : arg) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
    }, complex_variant);
    
    return 0;
}