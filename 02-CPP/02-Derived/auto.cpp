#include <iostream>

int main(void)
{
    auto var = 10;
    auto var2 = 10.5;
    auto var3 = 'a';
    auto var4 = "const char";
    auto var5 = std::string("string");
    
    const int x = 10;
    auto var6 = x;

    const auto var7 = x;
    auto &var8 = x;
    auto ptr = &x;

    auto arr = {1,2,3,4,5};

    return 0;
}