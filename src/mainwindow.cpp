#include "mainwindow.h"
#include "../assets/ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_10_clicked() // 按钮十所链接的函数
{
    Form *test = new Form; // 创建商品信息子窗口
    test->show();          // 子窗口展示
}

bool MainWindow::Set_Window()
{
    this->setWindowTitle("Supermarket Manage System");
    ui->lineEdit->setText("Supermarket Manage System"), ui->lineEdit->setReadOnly(true), ui->lineEdit->setFont(QFont("Segoe UI", 16, QFont::Bold)), ui->lineEdit->setAlignment(Qt::AlignCenter);
    ui->tableWidget->setHorizontalHeaderLabels({"Name", "Prod. date", "Price", "Quantity"}), ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->pushButton_4->setText("Initialize"), ui->pushButton_5->setText("Add"), ui->pushButton_6->setText("Delete"), ui->pushButton->setText("Scan");
    ui->pushButton_10->setText("Prod. info"), ui->pushButton_2->setText("Sell"), ui->pushButton_3->setText("Return"), ui->pushButton_9->setText("Save");
    ui->pushButton_7->setText("Cal sales"), ui->textEdit_2->setReadOnly(true), ui->textEdit_2->setFont(QFont("Microsoft YaHei UI", 16, QFont::Bold)), ui->textEdit_2->setText("0");
    return true;
}

inline bool MainWindow::Fill_Table(QSqlQuery &query, QString table_name, int &row, int n_col)
{
    QString sql_query = QString("select * from %1").arg(table_name);
    if (!Query_db_Talbe(query, sql_query, table_name, "Mainwindow"))
        return false;
    while (query.next())
    {
        ui->tableWidget->setRowCount(row + 1);
        for (int col = 0; col < n_col; ++col)
        {
            QString content;
            QVariant val = query.value(col + 2);
            if (col != 2)
                content = val.toString();
            else
                content = IntMoney_to_Str(val.toInt());
            QTableWidgetItem *itm = new QTableWidgetItem(content);
            ui->tableWidget->setItem(row, col, itm);
        }
        ++row;
    }
    return true;
}

inline bool MainWindow::operator<<(QString path)
{
    QFile ini_file(ini_file_path);
    if (!ini_file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(nullptr, "Error", "MainWindow: Can't open initialzing file!", QMessageBox::Ok);
        qDebug() << "MainWindow: Can't open initialzation file!";
        ini_file.close();
        return false;
    }
    QString sm_Name;
    while (!ini_file.atEnd())
    {
        QString line;
        short flag = 0;
        QString category, name, producion_date, color;
        int sm_Cash, quantity = 0, price = 0, maintienance_period = 0, guarantee_period = 0;
        while ((line != "\n") && (!ini_file.atEnd()))
        {
            line = ini_file.readLine();
            int index = 0;
            if ((flag != 3) && (flag != 4) && (flag != 5))
            {
                if ((index = line.indexOf(category_search)))
                {
                    if (!(index = line.indexOf(Name_search)))
                    {
                        if (flag)
                            flag = 2;
                        else
                            flag = 1;
                        sm_Name = (line.mid(index + Name_search_len)).trimmed();
                    }
                    else if (!(index = line.indexOf(Cash_search)))
                    {
                        if (flag)
                            flag = 2;
                        else
                            flag = 1;
                        sm_Cash = StrMoney_to_Int(line.mid(index + Cash_search_len));
                    }
                }
                else
                {
                    category = (line.mid(index + category_search_len)).trimmed();
                    if (category == "DailyGoods")
                        flag = 3;
                    else if (category == "food")
                        flag = 4;
                    else if (category == "ElectricalAppliance")
                        flag = 5;
                }
            }
            else
            {
                if (!(index = line.indexOf(name_search)))
                    name = (line.mid(index + name_search_len)).trimmed();
                else if (!(index = line.indexOf(quantity_search)))
                    quantity = (line.mid(index + quantity_search_len)).toInt();
                else if (!(index = line.indexOf(production_date_search)))
                    producion_date = Format_date(line.mid(index + production_date_search_len), '/', '-');
                else if (!(index = line.indexOf(price_search)))
                    price = StrMoney_to_Int(line.mid(index + price_search_len));
                else if (flag == 4)
                {
                    if (!(index = line.indexOf(guarantee_period_search)))
                        guarantee_period = (line.mid(index + guarantee_period_search_len)).toInt();
                }
                else if (flag == 5)
                {
                    if (!(index = line.indexOf(color_search)))
                        color = line.mid(index + color_search_len).trimmed();
                    else if (!(index = line.indexOf(maintenance_period_search)))
                        maintienance_period = (line.mid(index + maintenance_period_search_len)).toInt();
                }
            }
        }
        switch (flag)
        {
        case 2:
        {
            Supermarket SM(sm_Name, sm_Cash);
            break;
        }
        case 3:
        {
            DailyGoods(sm_Name, category, name, producion_date, price, quantity, sm_Goods_db_file_path);
            break;
        }
        case 4:
        {
            Food(sm_Name, category, name, producion_date, price, quantity, sm_Goods_db_file_path, guarantee_period);
            break;
        }
        case 5:
        {
            ElectricalAppliance(sm_Name, category, name, producion_date, price, quantity, sm_Goods_db_file_path, color, maintienance_period);
            break;
        }

        default:
            break;
        }
    }
    ini_file.close();
    return true;
}

inline bool MainWindow::operator>>(QString path)
{
    QFile save_file(save_file_path);
    if (!save_file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::critical(nullptr, "Error", "MainWindow: Can't open save file!", QMessageBox::Ok);
        qDebug() << "MainWindow: Can't open save file!";
        save_file.close();
        return false;
    }
    QTextStream out(&save_file);
    if (!Supermarket::Open_Supermarket_db())
        return false;
    QSqlQuery query_sm, query_gd;
    if (!Query_db_Talbe(query_sm, "select * from Supermarkets", "Supermarkets", "MainWindow"))
        return false;
    while (query_sm.next())
    {
        QString sm_name = query_sm.value(0).toString();
        out << "Name: " << sm_name << '\n'
            << "Cash: " << IntMoney_to_Str(query_sm.value(1).toInt()) << '\n'
            << '\n';
        short n_col = 0;
        for (short flag = 0; flag < 3; ++flag)
        {
            QSqlDatabase db;
            if (!Open_db(db, sm_Goods_db_file_path, "MainWindow", "Goods"))
                return false;
            QString tablet_name, sql_query;
            switch (flag)
            {
            case 0:
            {
                tablet_name = "DailyGoods", n_col = 5;
                break;
            }
            case 1:
            {
                tablet_name = "Food", n_col = 6;
                break;
            }
            case 2:
            {
                tablet_name = "ElectricalAppliance", n_col = 7;
                break;
            }

            default:
                break;
            }
            sql_query = QString("select * from %1 where supermarket_name == '%2'").arg(tablet_name).arg(sm_name);
            if (!Query_db_Talbe(query_gd, sql_query, tablet_name, "MainWindow"))
                return false;
            while (query_gd.next())
            {
                for (short col = 1; col <= n_col; ++col)
                {
                    switch (col)
                    {
                    case 1:
                    {
                        out << "category: " << query_gd.value(col).toString() << '\n';
                        break;
                    }
                    case 2:
                    {
                        out << "name: " << query_gd.value(col).toString() << '\n';
                        break;
                    }
                    case 3:
                    {
                        out << "production_date: " << Format_date(query_gd.value(col).toString(), '-', '/') << '\n';
                        break;
                    }
                    case 4:
                    {
                        out << "price: " << IntMoney_to_Str(query_gd.value(col).toInt()) << '\n';
                        break;
                    }
                    case 5:
                    {
                        out << "quantity: " << query_gd.value(col).toString() << '\n';
                        break;
                    }
                    case 6:
                    {
                        if (tablet_name == "Food")
                            out << "guarantee_period: " << query_gd.value(col).toString() << '\n';
                        else if (tablet_name == "ElectricalAppliance")
                            out << "color: " << query_gd.value(col).toString() << '\n';
                        break;
                    }
                    case 7:
                    {
                        out << "maintenance_period: " << query_gd.value(col).toString() << '\n';
                        break;
                    }

                    default:
                        break;
                    }
                }
                out << '\n';
            }
        }
    }
    return true;
}

void MainWindow::on_pushButton_4_clicked()
{
    Set_Window();
    if (!(*this << ini_file_path))
        return;
    QSqlDatabase Goods_db;
    if (!Open_db(Goods_db, sm_Goods_db_file_path, "MainWindow", "Goods"))
        return;
    QSqlQuery sql_query;
    int row = 0;
    if (!Fill_Table(sql_query, "DailyGoods", row, 4))
    {
        Goods_db.close();
        return;
    }
    if (!Fill_Table(sql_query, "Food", row, 4))
    {
        Goods_db.close();
        return;
    }
    if (!Fill_Table(sql_query, "ElectricalAppliance", row, 4))
    {
        Goods_db.close();
        return;
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    if (*this >> save_file_path)
        QMessageBox::information(nullptr, "Successful", "MainWindow: Saved!", QMessageBox::Ok);
    else
        return;
}

void MainWindow::on_pushButton_2_clicked()
{
    Sell_Dialog *dia = new Sell_Dialog;
    dia->show();
}
