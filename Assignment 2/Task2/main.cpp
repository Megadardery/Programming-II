#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    Stack s(5);
    s.print();
    s.push(6);
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    cout << s.isEmpty() << "\n";
    s.clear();
    cout << s.isEmpty() << "\n";
    s.print();
    cout << "\ndone\n";
    return 0;
}
