#include "complex.h"
#include <QtMath>

Complex::Complex()
{
}

Complex::Complex(double realPart, double imaginaryPart)
    :realPart(realPart), imaginaryPart(imaginaryPart)
{
}

Complex::Complex(const Complex &complex)
    :realPart(complex.realPart), imaginaryPart(complex.imaginaryPart)
{
}

Complex::Complex(double number)
    :realPart(number), imaginaryPart(0)
{
}

double Complex::getRealPart() const
{
    return realPart;
}

double Complex::getImaginaryPart() const
{
    return imaginaryPart;
}

std::istream& operator>>(std::istream &in, const Complex &complex)
{
    in >> complex.realPart;
    in >> complex.imaginaryPart;
    return in;
}

std::ostream& operator<<(std::ostream &out, const Complex &complex)
{
    if(complex.imaginaryPart == 0)
        out << complex.realPart;
    else
        out << "(" << complex.realPart << " + " << complex.getImaginaryPart() << "i)";
return out;
}

Complex operator+(const Complex &num1, const Complex &num2)
{
    return Complex(num1.getRealPart() + num2.getRealPart(), num1.getImaginaryPart() + num2.getImaginaryPart());
}

Complex operator-(const Complex &num1, const Complex &num2)
{
    return Complex(num1.getRealPart() - num2.getRealPart(), num1.getImaginaryPart() - num2.getImaginaryPart());
}

Complex operator*(const Complex &num1, const Complex &num2)
{
    return Complex(num1.getRealPart()*num2.getRealPart() - num1.getImaginaryPart()*num2.getImaginaryPart(), num1.getRealPart()*num2.getImaginaryPart() + num2.getRealPart()*num1.getImaginaryPart());
}

Complex operator*(double num1, const Complex &num2)
{
    return Complex(num1*num2.getRealPart(), num1*num2.getImaginaryPart());
}

Complex operator/(const Complex &num1, const Complex &num2)
{
    Complex numerator = num1*(Complex(num2.realPart, -num2.imaginaryPart));
    return Complex(numerator.getRealPart()/(num2.getRealPart()*num2.getRealPart() + num2.getImaginaryPart()*num2.getImaginaryPart()),
                         numerator.getImaginaryPart()/(num2.getRealPart()*num2.getRealPart() + num2.getImaginaryPart()*num2.getImaginaryPart()));
}

bool operator==(const Complex &num1, const Complex &num2)
{
    if(num1.realPart == num2.realPart && num1.imaginaryPart == num2.imaginaryPart)
        return true;

    return false;

}

bool operator==(const Complex &num1, double num2)
{
    if(num1.realPart == num2 && num1.imaginaryPart == 0)
        return true;

    return false;
}

Complex sqrt(const Complex &number)
{
    if(number.realPart < 0 && number.imaginaryPart == 0)
        return Complex(qSqrt(-number.realPart), 1);
}
