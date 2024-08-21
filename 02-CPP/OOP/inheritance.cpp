#include <iostream>
#include <ostream>

class ParentClass
{
    public:
        ParentClass(){
            std::cout << "Parent Class Default Constructor\n";
            this->a = 0;
        }
        ParentClass(int a)
        {
            std::cout << "Parent Class Constructor\n";
            this->a = a;
        }
        ~ParentClass(){
            std::cout << "Parent Class Destructor\n";

        }

        void set_a(int a);
        int  get_a();
        void square_a();
        void display(){
            std::cout << a << std::endl;
        }
    /* can be accessed only by classes that inherits it */    
    protected:
        int a;
};


class ChildClass : public ParentClass
{
    public:
        // can access parent class protected members
        // by default all inherited members are seen as private from outside code to this class
        // using ParentClass::ParentClass; // to use all base class constructors
        ChildClass(){
            std::cout << "Child Class Default Constructor\n";
            this->b = 0;
            // rely on parent constructor.
            ParentClass();
        }
        ChildClass(int b) : ParentClass(){
            std::cout << "Child Class Constructor\n";
            this->b = b; 
        }

        ChildClass(int a, int b) : ParentClass(a){
            std::cout << "Child Class Constructor\n";
            this->b = b; 
        }
        ~ChildClass(){
            std::cout << "Child Class Destructor\n";
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
    ChildClass c1{45,25};
    std::cout << c1.sum() << std::endl; 
    c1.display();
    
    return 0;
}