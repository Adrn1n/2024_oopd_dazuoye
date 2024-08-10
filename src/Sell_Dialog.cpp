#include "Sell_Dialog.h"
#include "../assets/ui_Sell_Dialog.h"

Sell_Dialog::Sell_Dialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::Sell_Dialog)
{
    ui->setupUi(this);
}

Sell_Dialog::~Sell_Dialog()
{
    delete ui;
}

void Sell_Dialog::on_add_btn_clicked()
{
    Sell_Add_Dialog *dia = new Sell_Add_Dialog();
    dia->show();
}
