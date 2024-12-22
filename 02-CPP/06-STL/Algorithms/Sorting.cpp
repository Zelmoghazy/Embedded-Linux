#include <algorithm>
#include <functional>
#include <ios>
#include <iterator>
#include <ostream>
#include <random>
#include <vector>
#include <iostream>
#include <numeric>


void printVector(const std::vector<int>& vec, const char *message) 
{
    std::cout << message << " ";
    for (int elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

// Custom struct to demonstrate sorting with objects
struct Person {
    std::string name;
    int age;
    
    // Constructor
    Person(std::string n, int a) : name(n), age(a) {}
};

// Functor for sorting Persons by age
struct ComparePersonByAge {
    bool operator()(const Person& a, const Person& b) const {
        return a.age < b.age;
    }
};

// Functor for sorting Persons by name length
struct ComparePersonByNameLength {
    bool operator()(const Person& a, const Person& b) const {
        return a.name.length() < b.name.length();
    }
};

int main(void) 
{
    std::vector<int> v = {3, 1, 4, 1, 5, 9};
    
    // Sort in ascending order
    std::sort(v.begin(), v.end()); // {1, 1, 3, 4, 5, 9}
    
    // Sort in descending order
    std::sort(v.begin(), v.end(), std::greater<int>()); // {9, 5, 4, 3, 1, 1}

    // Custom functor: only sort even numbers to the front
    std::sort(numbers.begin(), numbers.end(), [](int a, int b) {
        bool aIsEven = (a % 2 == 0);
        bool bIsEven = (b % 2 == 0);
        
        // If both are even or both are odd, use default comparison
        if (aIsEven == bIsEven) {
            return a < b;
        }
        
        // Move even numbers to the front
        return aIsEven > bIsEven;
    });

    // Partial sorting with nth_element
    std::vector<int> partialSort = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    
    // Partially sort to get the 3 smallest elements at the beginning
    std::nth_element(partialSort.begin(), partialSort.begin() + 2, partialSort.end());
    
    // Stable sorting (preserves relative order of equal elements)
    std::vector<int> stableSort = {4, 2, 4, 1, 3, 4};
    std::stable_sort(stableSort.begin(), stableSort.end());
    
    // Sorting with custom comparator using std::less and std::greater
    std::vector<int> customCompare = {5, 2, 8, 1, 9};
    std::sort(customCompare.begin(), customCompare.end(), std::less<int>());
    std::sort(customCompare.begin(), customCompare.end(), std::greater<int>());s

    // Sorting custom objects
    std::vector<Person> people = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 35},
        {"David", 20}
    };
    
    // Sort by age using custom functor
    std::sort(people.begin(), people.end(), ComparePersonByAge());
    
    // Sort by name length using another custom functor
    std::sort(people.begin(), people.end(), ComparePersonByNameLength());
    
    // Sort by age in descending order using lambda
    std::sort(people.begin(), people.end(), [](const Person& a, const Person& b) {
        return a.age > b.age;
    });

    return 0;
}