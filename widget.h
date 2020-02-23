#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
//#include "number.h"
#include "polinom.h"

class Widget : public QWidget
{
    Q_OBJECT

    QLabel *l1, *l2, *l3, *l4, *l5, *l6;
    QLineEdit *e1, *e2, *e3;

    QPushButton *b1;

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void roots();
    void output(Polinom *polinom);

signals:
    void mysignal(Polinom *polinom);
};

#endif // WIDGET_H
