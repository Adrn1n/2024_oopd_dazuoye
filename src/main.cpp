#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    MainWindow w; // 主窗口创建
    w.show();     // 主窗口展示
    return a.exec();
}
