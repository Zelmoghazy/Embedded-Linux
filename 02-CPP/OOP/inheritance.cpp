#include <iostream>
#include <ostream>

class ParentClass
{
    public:
        ParentClass(){
            this->a = 0;
        }
        ParentClass(int a)
        {
            this->a = a;
        }
        void set_a(int a);
        int get_a();
        void square_a();
    /* can be accessed only by classes that inherits it */    
    protected:
        int a;
};


class ChildClass : ParentClass
{
    public:
        // can access parent class protected members
        // by default all inherited members are seen as private from outside code to this class
        // using ParentClass::ParentClass; // to use all base class constructors
        ChildClass(){
            this->b = 0;
            // rely on parent constructor.
            ParentClass();
        }
        ChildClass(int b){
            this->b = b; 
        }
        int sum(){
            return a+b;
        }
    private:
        int b;
};

// you cannot inherit from final classes
class FinalClass final{
    int a;
    int b;
};

// class FinalClassChild : FinalClass{
// }; // Compiler error


int main(void)
{
    ChildClass c1(45);
    std::cout << c1.sum() << std::endl; 
    
    return 0;
}