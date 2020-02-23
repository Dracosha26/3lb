#include "widget.h"
#include <QDebug>
#include <iostream>
#include "polinom.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    l1 = new QLabel("a =",this);
    l1->setGeometry(20,20,50,30);
    e1 = new QLineEdit("1",this);
    e1->setGeometry(70,20,100,30);

    l2 = new QLabel("b =",this);
    l2->setGeometry(20,60,50,30);
    e2 = new QLineEdit("1",this);
    e2->setGeometry(70,60,100,30);

    l2 = new QLabel("c =",this);
    l2->setGeometry(20,100,50,30);
    e3 = new QLineEdit("1",this);
    e3->setGeometry(70,100,100,30);

    l4 = new QLabel("a*x^2 + bx + c",this);
    l4->setGeometry(20,140,90,30);
    l5 = new QLabel("x1 = ",this);
    l5->setGeometry(20,170,50,30);
    l6 = new QLabel("x2 =",this);
    l6->setGeometry(20,200,50,30);

    b1 = new QPushButton("Сalculate",this);
    b1->setGeometry(60,260,100,30);

    connect (b1,SIGNAL(pressed()),this,SLOT(roots()));
    connect (this,SIGNAL(mysignal(double)),
             this,SLOT(output(double)));

    setFixedSize(200,300);
}

Widget::~Widget()
{
    delete l2;
}

void Widget::roots()
{
    number a = e1->text().toDouble();
    number b = e2->text().toDouble();
    number c = e3->text().toDouble();

    Polinom *polinom = new Polinom(a, b, c);
    polinom->calculateX();
    emit mysignal(polinom);
}

void Widget::output(Polinom *polinom)
{
number a = polinom->getA();
number b = polinom->getB();
number c = polinom->getC();


//    cout << "Result of calculating the roots of the polynomial: " << endl << *polinom << endl;
//    if (polinom->getX()->size() == 1)
//        cout << "The equation has one root: x = " << polinom->getX()->first();
//    else if(polinom->getX()->size() == 2)
//        cout << "The equation has two roots:" << endl << "x1 = " << *polinom->getX()->begin() << " x2 = " << *(polinom->getX()->begin() + 1) << endl;
//    else
//        cout << "The equation has no roots";
}
