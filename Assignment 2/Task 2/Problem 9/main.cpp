#include <iostream>
#include "Complex.h"

using namespace std;

int main()
{
    const Complex i(0, 1);
    Complex num1(4.52, 3.2563);
    Complex num2(3.2156, 1.25648);

    cout << num1+num2 << endl;
    cout << num1-num2 << endl;
    cout << num1*num2 << endl;

    return 0;
}
