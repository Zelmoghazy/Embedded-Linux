#include <iostream>

int main(void)
{
    int val1;               // garbage
    int val2{};             // zero
    int val3(0);            
    int val4 = int{};


    std::cout << val1 << '\n';
    std::cout << val2 << '\n';

    std::string s1{};               // value initialization
    std::string s2("hello");        // Direct initialization
    std::string s3 = "hello";       // Copy initialization
    std::string s4{'a', 'b', 'c'};  // List initialization

    char a[3] = {'a', 'b'};         // aggregate initialization
    char& c = a[0];                 // Reference initialization


    float dec = 3.14f;
    int num = dec;      // allowed
    // int num2{dec};      // error no implicit casting is allowed
    int num2{static_cast<int>(dec)};      // error no implicit casting is allowed
}