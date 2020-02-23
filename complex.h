#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{
public:
    Complex();

    Complex(double realPart, double imaginaryPart);

    Complex(const Complex &complex);

    Complex(double number);

    double getRealPart() const;

    double getImaginaryPart() const;

    friend std::istream& operator>>(std::istream &in, const Complex &complex);

    friend std::ostream& operator<<(std::ostream &out, const Complex &complex);

    friend Complex operator+(const Complex &num1, const Complex &num2);

    friend Complex operator-(const Complex &num1, const Complex &num2);

    friend Complex operator*(const Complex &num1, const Complex &num2);

    friend Complex operator*(double num1, const Complex &num2);

    friend Complex operator/(const Complex &num1, const Complex &num2);

    friend bool operator==(const Complex &num1, const Complex &num2);

    friend bool operator==(const Complex &num1, double num2);

    friend Complex sqrt(const Complex &number);

    //static double sqrt(double number);


private:
    double realPart;
    double imaginaryPart;
};

#endif // COMPLEX_H
