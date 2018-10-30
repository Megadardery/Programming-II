#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

using namespace std;

class Complex
{
    private:
        double real;
        double imaginary;
    public:
        Complex();
        Complex(double real, double imaginary);
        Complex(double real);

        friend bool operator == (Complex&, Complex&);
        friend Complex& operator + (Complex&, Complex&);
        friend Complex& operator - (Complex&, Complex&);
        friend Complex& operator * (Complex&, Complex&);
        friend istream& operator >>(istream& in, Complex&);
        friend ostream& operator <<(ostream& out, Complex&);

        virtual ~Complex();

    protected:
};

#endif // COMPLEX_H
