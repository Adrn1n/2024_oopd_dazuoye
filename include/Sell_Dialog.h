#ifndef SELL_DIALOG_H
#define SELL_DIALOG_H

#include <QDialog>

#include "Sell_Add_Dialog.h"

namespace Ui
{
    class Sell_Dialog;
}

class Sell_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Sell_Dialog(QWidget *parent = nullptr);
    ~Sell_Dialog();

private:
    Ui::Sell_Dialog *ui;

private slots:
    void on_add_btn_clicked();
};

#endif // SELL_DIALOG_H
