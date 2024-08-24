#include <algorithm>
#include <cctype>
#include <iostream>
#include <ostream>
#include <string>

class EnhancedString : public std::string
{
    public:
        using std::string::string; // use all constructors of parent class

    // add new functionality
    bool starts_with(std::string const& prefix)
    {
        if(this->find(prefix) == 0){
            return true;
        }else{
            return false;
        }
    }

    bool end_with(std::string const& suffix)
    {
        if(this->rfind(suffix) == 0){
            return true;
        }else{
            return false;
        }
    }

    void to_upper()
    {
        std::transform(this->begin(), this->end(), this->begin(), ::toupper);
    }

    void to_lower()
    {
        std::transform(this->begin(), this->end(), this->begin(), ::tolower);
    }

    void reverse()
    {
        std::reverse(this->begin(), this->end());
    }

};

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
    std::string s7(s2, 0);                // Substring Constructor

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
    str += " World";
    std::string sub = str.substr(6, 5);  // Extract substring
    size_t pos = str.find("world");      // Find first occurrence, ret std::strong::npos if not found
    size_t rpos = str.rfind("l");        // Find last occurrence
    int result = str.compare("Hello");   // Compare strings

    // Concatenation
    std::string s8 = s1 + s2;        // Concatenate strings

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

    // Raw Strings
    
    // Example 1: A simple raw string
    std::string raw_string = R"(This is a raw string. It can contain "quotes" and \backslashes\ without needing to escape them.)";
    std::cout << raw_string << std::endl;

    // Example 2: A raw string with line breaks
    std::string multiline_string = R"(This is a raw string
    that spans multiple lines
    without needing newline characters)";
    std::cout << multiline_string << std::endl;

    // Example 3: A raw string with a custom delimiter "DELIM"
    std::string rawStringWithDelimiter = R"delim(This is a raw string that contains parentheses () and even ))).
    You can use custom delimiters to avoid ending the string prematurely.)delim";

    std::cout << "Raw String with Delimiter:" << std::endl;
    std::cout << rawStringWithDelimiter << std::endl;


    // Adding funtionality to the string class
    
    EnhancedString estr = "Hello world";

    std::cout << estr.starts_with("Hello")<<std::endl;;
    std::cout << estr.end_with("Hello")<<std::endl;

    estr.to_upper();

    std::cout << estr << std::endl;

    estr.to_lower();

    std::cout << estr << std::endl;

    estr.reverse();

    std::cout << estr << std::endl;


    return 0;
}
