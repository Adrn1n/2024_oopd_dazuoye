#include "Sell_Add_Dialog.h"
#include "../assets/ui_Sell_Add_Dialog.h"

Sell_Add_Dialog::Sell_Add_Dialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::Sell_Add_Dialog)
{
    ui->setupUi(this);
}

Sell_Add_Dialog::~Sell_Add_Dialog()
{
    delete ui;
}
