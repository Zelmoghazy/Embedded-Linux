#include <iostream>
#include <iomanip>
#include <cstring>

#define width 20

void ascii_table(int ascii_low = 32, int ascii_high=126)
{
    const char *header_1 = "char";
    const char *header_2 = "Ascii";

    std::cout << '+' << std::setw(width) << std::setfill('-') << '+' << std::setw(width) << std::setfill('-') << '+' << '\n'
    
              << '|' << std::setw((width/2+strlen(header_1)/2)) << std::setfill(' ') << header_1
              << std::setw((width/2-strlen(header_2)/2))  << '|' 

              << std::setw((width/2+strlen(header_2)/2))  << header_2 
              << std::setw((width/2-strlen(header_2)/2))  << '|' << '\n'

              << '+' << std::setw(width) << std::setfill('-') << '+' << std::setw(width) << std::setfill('-') << '+' << '\n';

    for(size_t i = ascii_low; i < ascii_high; i++){
        std::cout << '|' << std::setw(width/2) << std::setfill(' ') << static_cast<char>(i)
                  << std::setw(width/2)  << "|" 
                  << std::setw(width/2)  <<  i 
                  << std::setw(width/2)  << "|" << '\n';
    }
}

int main(void)
{
    ascii_table();
    return 0;
}