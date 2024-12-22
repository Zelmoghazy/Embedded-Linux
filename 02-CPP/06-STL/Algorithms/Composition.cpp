#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>

void basicPredicateComposition() 
{
    std::cout << "Basic Predicate Composition\n";

    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Simple predicate composition: find first even number greater than 5
    auto it = std::find_if(numbers.begin(), numbers.end(), 
                           [](int x) { return x > 5 && x % 2 == 0; });

    if (it != numbers.end()) {
        std::cout << "First even number > 5: " << *it << std::endl;
    }
}

/*
    Using Bind and Function Composition
    Note that bind is not lightweight construct and leads
    to longer compile times, so should be used when really needed
 */
void functionCompositionWithBind() 
{
    std::cout << "\nFunction Composition with Bind\n";
    std::vector<int> numbers = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    // Compose a function to check if a number is divisible by a specific divisor
    auto isDivisibleBy = [](int divisor, int num) {
        return num % divisor == 0;
    };

    // Use std::bind to create a predicate for divisibility by 3
    // and add a placeholder for required number to check
    auto isDivisibleByThree = std::bind(isDivisibleBy, 3, std::placeholders::_1);

    // Find first number divisible by 3
    auto it = std::find_if(numbers.begin(), numbers.end(), isDivisibleByThree);

    if (it != numbers.end()) {
        std::cout << "First number divisible by 3: " << *it << std::endl;
    }
}

// Complex Composition with Multiple Transformations
void complexFunctionComposition() 
{
    std::cout << "\nComplex Function Composition\n";
    std::vector<std::string> words = {"apple", "banana", "cherry", "date", "elderberry"};

    // Compose multiple transformations
    auto lengthGreaterThan = [](size_t length, const std::string& str) {
        return str.length() > length;
    };

    auto startsWithChar = [](char c, const std::string& str) {
        return !str.empty() && str[0] == c;
    };

    // Compose predicates using bind
    auto longWordsStartingWithB = std::bind(
        std::logical_and<bool>(),
        std::bind(lengthGreaterThan, 4, std::placeholders::_1),
        std::bind(startsWithChar, 'b', std::placeholders::_1)
    );

    // Find words that are longer than 4 characters and start with 'b'
    auto it = std::find_if(words.begin(), words.end(), longWordsStartingWithB);

    if (it != words.end()) {
        std::cout << "First long word starting with 'b': " << *it << std::endl;
    }
}

// Advanced Composition with Custom Comparators
void advancedCompositionWithComparators() {
    std::cout << "\nAdvanced Composition with Comparators\n";
    
    struct Person {
        std::string name;
        int age;
        double salary;
    };

    std::vector<Person> people = {
        {"Alice", 30, 50000.0},
        {"Bob", 25, 45000.0},
        {"Charlie", 35, 60000.0},
        {"David", 28, 55000.0}
    };

    // Compose complex sorting and filtering criteria
    auto sortByMultipleCriteria = [](const Person& a, const Person& b) {
        // Primary sort: age, Secondary sort: salary
        if (a.age != b.age) return a.age < b.age;
        return a.salary < b.salary;
    };

    // Sort people using the composed comparator
    std::sort(people.begin(), people.end(), sortByMultipleCriteria);

    std::cout << "Sorted People (by age, then salary):\n";
    for (const auto& person : people) {
        std::cout << person.name << ": " << person.age 
                  << " years, $" << person.salary << std::endl;
    }

    // Filtering with composed predicate
    auto isYoungHighEarner = [](const Person& p) {
        return p.age < 35 && p.salary > 50000.0;
    };

    auto it = std::find_if(people.begin(), people.end(), isYoungHighEarner);

    if (it != people.end()) {
        std::cout << "Young high earner found: " 
                  << it->name << std::endl;
    }
}

// Functional Composition with Transform and Accumulate
void functionalCompositionWithTransformAccumulate()
{
    std::cout << "\nFunctional Composition with Transform and Accumulate\n";
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Compose a series of transformations
    std::vector<int> transformed(numbers.size());
    
    // Transform: square each number, then multiply by 2
    std::transform(numbers.begin(), numbers.end(), transformed.begin(), 
        [](int x) { return x * x * 2; });

    // Accumulate with composition
    int sum = std::accumulate(transformed.begin(), transformed.end(), 0, 
        [](int acc, int val) { 
            // Accumulate only values greater than 10
            return val > 10 ? acc + val : acc; 
        });

    std::cout << "Transformed and filtered sum: " << sum << std::endl;

    // Print transformed values
    std::cout << "Transformed values: ";
    for (int val : transformed) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() 
{
    basicPredicateComposition();
    functionCompositionWithBind();
    complexFunctionComposition();
    advancedCompositionWithComparators();
    functionalCompositionWithTransformAccumulate();

    return 0;
}