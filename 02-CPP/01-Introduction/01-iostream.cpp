#include <ios>
#include <iostream>
#include <ostream>
#include <iomanip>
// #include <format>
// #include <print>

int main(void)
{
    std::cout << "Hello, World!\n";
    
    std::ostream& output = std::cout;
    output << "Hello world" << std::endl;

    int x = 5;

    std::cout << "Value : " << x << std::endl;
    std::cout << "Value : " << x << "\n";

    // cpp20 only
    // std::cout << std::format("Value : {}\n",x);

    // cpp23 only
    // std::println("Hello {}", "World!");

    std::cout << "Enter a number: ";
    std::cin >> x;

    std::cout << "Entered number is : " << x << '\n';

    // I/O manipulators
    std::cout << "Set width: " << std::setw(6) << 42 << '\n';

    std::cout << "Set precision: " << std::setprecision(4) << 3.14159265359 << '\n';

    std::cout << "Scientific: " << std::scientific << 1234.14159265359 << '\n';

    int num = 42;
    std::cout << "Hex :" << std::hex << num << std::dec << '\n';      // reset to decimal
    std::cout << "Hex :" << std::hex << std::showbase << num << '\n';
    std::cout << "Oct :" << std::oct << num << '\n';

    // Reset
    std::cout << "Dec :" << std::dec << num << '\n';

    std::cout << std::setfill('#') << "i: " << std::setw(12) << num <<'\n';

    std::cout<<false<<"\n";
    std::cout << std::boolalpha;   
    std::cout<<false<<"\n";

}