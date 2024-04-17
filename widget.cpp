#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    activeBuyButton(money);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money += diff;
    activeBuyButton(money);
    ui->lcdNumber->display(money);
}

void Widget::activeBuyButton(int money)
{
    ui->pbCoffee->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 150);
    ui->pbMilk->setEnabled(money >= 200);
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    char msg[4096];
    int change_500, change_100, change_50, change_10;
    change_500 = money / 500;
    money %= 500;
    change_100 = money / 100;
    money %= 100;
    change_50 = money / 50;
    money %= 50;
    change_10 = money / 10;
    changeMoney(-money);
    snprintf(msg, sizeof(msg), "500: %d\n100: %d\n50: %d\n10: %d", change_500, change_100, change_50, change_10);
    QMessageBox::information(this, "Change", msg);
}

