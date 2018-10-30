#include "Complex.h"

Complex::Complex()
{
    this->real = 0;
    this->imaginary = 0;
}

Complex::Complex(double real, double imaginary){
    this->real = real;
    this->imaginary = imaginary;
}

Complex::Complex(double real){
    this->real = real;
    this->imaginary = 0;
}

Complex::~Complex()
{
    //dtor
}

    bool operator == (Complex& Fir, Complex& Sec){
        if(Fir.real == Sec.real && Fir.imaginary == Sec.imaginary)
            return 1;
        return 0;
    }
    Complex& operator + (Complex& Fir, Complex& Sec){
        Complex Sum(Fir.real+Sec.real, Fir.imaginary+Sec.imaginary);
        return Sum;
    }
    Complex& operator - (Complex& Fir, Complex& Sec){
        Complex Sub(Fir.real-Sec.real, Fir.imaginary-Sec.imaginary);
        return Sub;
    }
    Complex& operator * (Complex& Fir, Complex& Sec){
        Complex Pro(Fir.real*Sec.real-Fir.imaginary*Sec.imaginary,Fir.real*Sec.imaginary+Fir.imaginary*Sec.real);
        return Pro;
    }
    istream& operator >>(istream& in, Complex& c){
        in >> c.real >> c.imaginary;
    }
    ostream& operator <<(ostream& out, Complex& c){
        if(c.imaginary == 1)
            out << c.real << " + " << "i";
        else
            out << c.real << " + " << c.imaginary << "i";
        return out;
    }
