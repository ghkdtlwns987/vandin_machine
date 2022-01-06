#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setControl();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int coin)
{
    money += coin;
    ui->lcdNumber->display(money);
    setControl();
}
void Widget::print_MessageBox(){
    int coin_500 = money / 500;
    int coin_100 = (money % 500) / 100;
    int coin_50 = (money % 100) / 50;
    int coin_10 = (money / 50) / 10;

    QMessageBox msgBox;
    msgBox.addButton(QMessageBox::Yes);
    msgBox.setText("500원 : " +QString::number(coin_500) + " 100원 : " +QString::number(coin_100) + " 50원 : " +QString::number(coin_50) + " 10원 : " +QString::number(coin_10)) ;
    msgBox.exec();

    money = 0;
}

void Widget::setControl()
{
    ui->pbCoffee->setEnabled(money >= 200);
    ui->pbMilk->setEnabled(money >= 100);
    ui->pbTea->setEnabled(money >= 150);

}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
//    money += 500;
//    ui->lcdNumber->display(money);
}

void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-200);

}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);

}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbReset_clicked()
{
    print_MessageBox();
}
