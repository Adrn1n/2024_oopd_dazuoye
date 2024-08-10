#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form.h" //导入子窗口文件

#include <QFile>
#include <QTextStream>
#include <QFont>

#include "Supermarket.h"
#include "DailyGoods.h"
#include "Food.h"
#include "ElectricalAppliance.h"
#include "Query_db_Table.h"
#include "Money_Convert.h"
#include "Format_Date.h"

#include "Sell_Dialog.h"

const QString ini_file_path = "../assets/market_in.txt";
const QString save_file_path = "../assets/market_out.txt";
const QString sm_Goods_db_file_path = "../assets/Goods.db";

const QString Name_search = "Name: ", Cash_search = "Cash: ", category_search = "category: ", name_search = "name: ", production_date_search = "production_date: ", price_search = "price: ", quantity_search = "quantity: ", guarantee_period_search = "guarantee_period: ", color_search = "color: ", maintenance_period_search = "maintenance_period: ";
const short Name_search_len = Name_search.length(), Cash_search_len = Cash_search.length(), category_search_len = category_search.length(), name_search_len = name_search.length(), production_date_search_len = production_date_search.length(), price_search_len = price_search.length(), quantity_search_len = quantity_search.length(), guarantee_period_search_len = guarantee_period_search.length(), color_search_len = color_search.length(), maintenance_period_search_len = maintenance_period_search.length();

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool Set_Window();

private slots:
    void on_pushButton_10_clicked(); // 按钮十链接函数声明
    void on_pushButton_4_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    inline bool Fill_Table(QSqlQuery &query, QString table_name, int &row, int n_col);
    inline bool operator<<(QString path);
    inline bool operator>>(QString path);
};
#endif // MAINWINDOW_H
