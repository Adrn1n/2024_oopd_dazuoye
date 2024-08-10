#ifndef SELL_ADD_DIALOG_H
#define SELL_ADD_DIALOG_H

#include <QDialog>

namespace Ui
{
    class Sell_Add_Dialog;
}

class Sell_Add_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Sell_Add_Dialog(QWidget *parent = nullptr);
    ~Sell_Add_Dialog();

private:
    Ui::Sell_Add_Dialog *ui;
};

#endif // SELL_ADD_DIALOG_H
