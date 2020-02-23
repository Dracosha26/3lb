#ifndef POLINOM_H
#define POLINOM_H

#include "number.h"
#include <QVector>
#include <iostream>

class Polinom
{
public:
    Polinom(number a, number b, number c);

    number getA();

    number getB();

    number getC();

    QVector< number >* getX();

    void calculateX();

    friend std::ostream& operator<<(std::ostream &out, const Polinom &polinom);

private:
    number a;
    number b;
    number c;
    QVector< number > *x;
};

#endif // POLINOM_H
