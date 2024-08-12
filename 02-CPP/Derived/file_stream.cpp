#include <iostream>
#include <ostream>
#include <sstream>

int main(void)
{
    std::string frame = "Zeyad 123 1450.5";

    std::string name;
    int id;
    double salary;

    std::stringstream iss(frame);

    iss >> name >> id >> salary;

    std::cout << "Name : " << name << std::endl
              << "ID :" << id      << std::endl
              << "Salary :" << salary << std::endl;

}