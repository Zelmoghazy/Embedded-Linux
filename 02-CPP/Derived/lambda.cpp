#include <algorithm>
#include <array>
#include <iostream>
#include <functional>
#include <ostream>
#include <vector>


int main(void)
{
    /*
        std::function<return(params)>
        [Capture](Parameters) -> return type {
            // body
        };
    */
    int offset = 100;
    int a = 5;
    int b = 10;

    /* Scope of lambda is standalone */
    // auto sum = [](int x, int y) -> int {
    //     return x+y+offset;                  // Error cannot use outside variables
    // }; 

    /*
        - [=] : pass everything by value
        - [&] : pass everything by reference 
     */

     /* 
        arguments passed as parameters get treated just like they would if you were passing them to any function.
        Variables captured by the brackets become a part of the lambda object. 
    */
    auto sum = [offset](int x, int y) -> int {
        return x+y+offset;
    };

    auto mul = [=](int x, int y) -> int {
        return (x+a) * (y+b);
    };

    std::cout << sum(2,3) << std::endl;
    std::cout << mul(2,3) << std::endl;



    std::string str{ "this is a string!" };
    
    auto lambda1 = [&](int num) { std::cout << str << num << '\n'; };
    
    // is (almost) equivalent to...
    
    struct WhateverType {
        WhateverType(std::string& ref) : m_str{ ref } {}
        void operator()(int num) {
            std::cout << m_str << num << '\n';
        }
        std::string& m_str; // captures are just members of the class
    } lambda2{ str };


    auto compare = [offset](int num1, int num2){        // can deduce the return type
        return (num1+offset) < (num2 + offset);
    };

    std::vector<int> v = {55,6,8,9,66,5,2,3,8,4,9,52,5,5,46,4};
    std::sort(v.begin(), v.end(), compare);

    for (auto num : v) {
        std::cout << num << " ";
    }
    std::cout << '\n';



    int temp = 10;

    // Cannot assign to a variable captured by copy in a non-mutable lambda -> private
    [temp](int number) mutable{
        temp = 100;
        std::cout <<temp << std::endl;
    }(3);

    std::cout <<temp << std::endl;

    [&temp](int number) mutable{
        temp = 100;
        std::cout <<temp << std::endl;
    }(3);

    std::cout <<temp << std::endl;


    void (*pf)(int x) = [](int x)
    {
        std::cout << "Pointer to function \n";      // allowed
    };
    pf(3);


    // Error not pointer to function anymore
    /* 
        void (*pf2)(int x) = [temp](int x)
        {
            std::cout << "Pointer to function \n";      // not allowed 
        };

     */

    std::function<void(int x)> pf2 = [temp](int x)
    {
        std::cout << "std::function" << temp <<  '\n';      // allowed
    };
    pf2(3);

    /* ------------------------------------ */

    [&v = temp, x=100](){
        std::cout << v << std::endl;
        std::cout << x << std::endl;
        v = 55;
        std::cout << v << std::endl;
    }();
    std::cout << temp << std::endl;

    /* ------------------------------------ */

    int sum2 = 0;
    std::array<int, 10> arr = {0,1,2,3,4,5,6,7,8,9};
    std::for_each(arr.begin(), arr.end(), [&sum2](int &n){sum2 += n;});
    std::cout << "sum of arrray : " << sum2 << std::endl;

}