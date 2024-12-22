#include <iostream>
#include <optional>
#include <string>

// Function that might return an optional value
std::optional<int> divide(int numerator, int denominator) 
{
    if (denominator == 0) {
        // Return an empty optional if division by zero
        return std::nullopt;
    }
    // Return the result wrapped in an optional
    return numerator / denominator;
}

// Function that might return an optional object
std::optional<std::string> get_user_name(int user_id) 
{
    // Simulate a database lookup
    if (user_id <= 0) {
        return std::nullopt;
    }
    
    // Simulated user names
    switch (user_id) {
        case 1: return "Alice";
        case 2: return "Bob";
        case 3: return "Charlie";
        default: return std::nullopt;
    }
}

int main() {
    // Demonstrating optional with division
    std::cout << "Division Examples:" << std::endl;
    
    // Successful division
    auto result1 = divide(10, 2);
    if (result1) {
        std::cout << "10 / 2 = " << *result1 << std::endl;
    } else {
        std::cout << "Division failed" << std::endl;
    }
    
    // Division by zero
    auto result2 = divide(10, 0);
    if (result2) {
        std::cout << "10 / 0 = " << *result2 << std::endl;
    } else {
        std::cout << "Division by zero is not allowed" << std::endl;
    }
    
    // Demonstrating optional with user lookup
    std::cout << "\nUser Lookup Examples:" << std::endl;
    
    // Successful user lookup
    auto user1 = get_user_name(1);
    if (user1) {
        std::cout << "User 1 name: " << *user1 << std::endl;
    } else {
        std::cout << "User 1 not found" << std::endl;
    }
    
    // Failed user lookup
    auto user4 = get_user_name(4);
    if (user4) {
        std::cout << "User 4 name: " << *user4 << std::endl;
    } else {
        std::cout << "User 4 not found" << std::endl;
    }
    
    // Using value_or() to provide a default
    std::cout << "\nValue Or Examples:" << std::endl;
    auto safe_divide = divide(10, 0).value_or(-1);
    std::cout << "Safe divide result: " << safe_divide << std::endl;
    
    auto user_name = get_user_name(0).value_or("Unknown");
    std::cout << "User name: " << user_name << std::endl;
    
    return 0;
}