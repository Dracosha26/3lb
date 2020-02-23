#include "polinom.h"
#include <math.h>

Polinom::Polinom(number a, number b, number c)
    :a(a), b(b), c(c)
{
    x = new QVector< number >;
}

number Polinom::getA()
{
    return a;
}

number Polinom::getB()
{
    return b;
}

number Polinom::getC()
{
    return c;
}

QVector< number >* Polinom::getX()
{
    return x;
}

void Polinom::calculateX()
{

    number D = b*b - 4*a*c;

    if(D == 0)
    {
        x->push_back(-1*b/(2*a));
    }
    else
    {
        x->push_back((-1*b + sqrt(D))/(2*a));
        x->push_back((-1*b - sqrt(D))/(2*a));
    }
}

std::ostream& operator<<(std::ostream &out, const Polinom &polinom)
{
    out << polinom.a << "x^2 + " << polinom.b << "x + " << polinom.c;
    return out;
}
