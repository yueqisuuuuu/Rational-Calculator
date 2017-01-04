#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    ui->denSpinBox->setRange(std::numeric_limits<int>::lowest(),
                           std::numeric_limits<int>::max());
    ui->numSpinBox->setRange(std::numeric_limits<int>::lowest(),
                           std::numeric_limits<int>::max());
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::on_plusButton_clicked()
{
    Rational a (ui->i1_numSpinBox->value(), ui->i1_denSpinBox->value());
    Rational b (ui->i2_numSpinBox->value(), ui->i2_denSpinBox->value());
    Rational c = a+b;
    ui->numSpinBox->setValue(c.get_num());
    ui->denSpinBox->setValue(c.get_den());
}

void Calculator::on_minusButton_clicked()
{
    Rational a (ui->i1_numSpinBox->value(), ui->i1_denSpinBox->value());
    Rational b (-(ui->i2_numSpinBox->value()), ui->i2_denSpinBox->value());
    Rational c = a+b;
    ui->numSpinBox->setValue(c.get_num());
    ui->denSpinBox->setValue(c.get_den());
}

void Calculator::on_timesButton_clicked()
{
    Rational a (ui->i1_numSpinBox->value(), ui->i1_denSpinBox->value());
    Rational b (ui->i2_numSpinBox->value(), ui->i2_denSpinBox->value());
    Rational c = a*b;
    ui->numSpinBox->setValue(c.get_num());
    ui->denSpinBox->setValue(c.get_den());
}

void Calculator::on_divideButton_clicked()
{
    Rational a (ui->i1_numSpinBox->value(), ui->i1_denSpinBox->value());
    Rational b (ui->i2_denSpinBox->value(), ui->i2_numSpinBox->value());

    Rational c = a*b;
    ui->numSpinBox->setValue(c.get_num());
    ui->denSpinBox->setValue(c.get_den());
}
