#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "rational.h"
#include <QWidget>

namespace Ui {
class Calculator;
}

class Calculator : public QWidget
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

private slots:
    void on_plusButton_clicked();

    void on_minusButton_clicked();

    void on_timesButton_clicked();

    void on_divideButton_clicked();

private:
    Ui::Calculator *ui;
};

#endif // Calculator_H
