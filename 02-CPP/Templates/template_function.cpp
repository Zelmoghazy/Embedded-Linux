#include <iostream>
using namespace std;

// Function template
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main(void) 
{
    int     intResult       = add(5, 10);           // T is deduced to be int
    double  doubleResult    = add(5.5, 3.2);        // T is deduced to be double
    float   floatResult     = add(3.3f, 4.4f);      // T is deduced to be float

    cout << "intResult: " << intResult << endl;
    cout << "doubleResult: " << doubleResult << endl;
    cout << "floatResult: " << floatResult << endl;

    return 0;
}
