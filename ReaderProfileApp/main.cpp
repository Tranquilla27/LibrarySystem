#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.setWindowTitle("Личный кабинет читателя");
    window.resize(700, 500);
    window.show();
    return app.exec();
}