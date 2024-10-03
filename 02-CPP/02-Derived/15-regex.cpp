#include <iostream>
#include <regex>
#include <string>
#include <vector>

int main(void)
{
    std::string frame = "my number is 01236464464, my e-mail is zeyad@gmail.com";

    std::regex pattern ("([0-9]+)");
    std::smatch match;
    std::regex_search(frame,match,pattern);
    std::cout << match.str() << std::endl;
    
    return 0;
}

