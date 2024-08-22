#include <iostream>
#include <string>

int main(void) 
{
    // Construction and Initialization
    std::string s;                        // Default constructor
    std::string str = "Hello";            // const char*
    std::string s1("Hello");              // Parameterized constructor
    std::string s2(5, 'a');               // "aaaaa"
    std::string s3(s1);                   // Copy constructor
    std::string s4(std::move(s3));        // Move constructor
    std::string s5(s1.begin(),s1.end());  // Range Constructor
    std::string s6(s2, 0, 3);             // Substring Constructor
    std::string s6(s2, 0);                // Substring Constructor

    // Capacity Functions
    size_t size = s1.size();          
    size_t len = s1.length();         
    size_t cap = s1.capacity();       
    size_t max_size = s1.max_size();      
    bool isEmpty = s.empty();        // Check if empty
    s1.resize(10);              // Resize string
    s1.resize(10, 'x');              // Resize string

    // Accessing Characters
    char c = s1[0];                 // Access using operator[]
    char d = s1.at(1);              // Access using at()
    char first = s1.front();        // First character
    char last = s1.back();          // Last character

    // Modification
    s1.append(" world");            // Append string
    s1 += "!";                      // Append character
    s1.insert(5, " brave");         // Insert string
    s1.erase(5, 6);                 // Erase portion of string
    s1.replace(6, 5, "world");      // Replace portion of string
    s1.clear();

    // String Operations
    std::string sub = s1.substr(6, 5);  // Extract substring
    size_t pos = s1.find("world");      // Find first occurrence, ret std::strong::npos if not found
    size_t rpos = s1.rfind("l");        // Find last occurrence
    int result = s1.compare("Hello");   // Compare strings

    // Concatenation
    std::string s7 = s1 + s2;        // Concatenate strings

    // Conversion
    const char* cstr = s1.c_str();   // Get C-style string
    std::string numStr = std::to_string(123); // Convert number to string

    // Iterators
    for (auto it = s1.begin(); it != s1.end(); ++it) {
        std::cout << *it;            // Print each character
    }
    std::cout << std::endl;

    for (auto it = s1.rbegin(); it != s1.rend(); ++it) {
        std::cout << *it;            // Reverse iteration
    }
    std::cout << std::endl;



    // String Input/Output
    std::cin >> s;                   // Input until space
    std::getline(std::cin, s);       // Input until newline
    std::cout << s1 << std::endl;    // Output string

    // Swapping
    s1.swap(s2);                     // Swap strings

    return 0;
}
