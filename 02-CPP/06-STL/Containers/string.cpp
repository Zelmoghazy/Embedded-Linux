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

/* Return line without beginning or end whitespace */
std::string trim(const std::string& str) {
    const auto start = str.find_first_not_of(" \t\r\n");
    // entire line is white space
    if (start == std::string::npos){
        return "";
    } 
    const auto end = str.find_last_not_of(" \t\r\n");
    return str.substr(start, end - start + 1);
}

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


    std::string str1 = "123ABC456";
    size_t pos1 = str1.find_first_not_of("123456");
    if (pos1 != std::string::npos) {
        std::cout << "find_first_not_of: First character not in '123456' is at position: " << pos1 << '\n';
        std::cout << "Character: " << str1[pos1] << '\n'; // Output: A
    } else {
        std::cout << "find_first_not_of: No character found that is not in '123456'.\n";
    }

    std::string str2 = "abcdef123";
    size_t pos2 = str2.find_first_of("123");
    if (pos2 != std::string::npos) {
        std::cout << "find_first_of: First occurrence of any character in '123' is at position: " << pos2 << '\n';
        std::cout << "Character: " << str2[pos2] << '\n'; // Output: 1
    } else {
        std::cout << "find_first_of: No character found in '123'.\n";
    }

    std::string str3 = "abc123abc";
    size_t pos3 = str3.find_last_of("abc");
    if (pos3 != std::string::npos) {
        std::cout << "find_last_of: Last occurrence of any character in 'abc' is at position: " << pos3 << '\n';
        std::cout << "Character: " << str3[pos3] << '\n'; // Output: c
    } else {
        std::cout << "find_last_of: No character found in 'abc'.\n";
    }

    std::string str4 = "abc123abc";
    size_t pos4 = str4.find_last_not_of("abc");
    if (pos4 != std::string::npos) {
        std::cout << "find_last_not_of: Last character not in 'abc' is at position: " << pos4 << '\n';
        std::cout << "Character: " << str4[pos4] << '\n'; // Output: 3
    } else {
        std::cout << "find_last_not_of: All characters are in 'abc'.\n";
    }

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

    // String view 

    std::string str{"foobar"};
    std::string_view bar{str.c_str(), str.size()};
    bar.remove_prefix(3);
    assert(bar == "bar");


    return 0;
}
