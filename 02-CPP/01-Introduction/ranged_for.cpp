#include <iostream>
#include <ostream>
#include <vector>

int main(void)
{
    // ranged for loop
    int a[] = {1,2,3,4,5};

    // c-style
    for (size_t i = 0; i<sizeof(a)/sizeof(a[0]); i++)
    {
        std::cout << a[i] << '\n';
    }

    // for (type iteration_var : container)
    for (int val : a)
    {
        std::cout << val << '\n';
    }

    std::vector<int> numbers = {1, 2, 3, 4, 5};

    for (int number : numbers) {
        std::cout << number << '\n';
    }

    return 0;
}
