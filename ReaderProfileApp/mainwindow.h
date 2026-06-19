#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTableWidget>
#include <QGroupBox>
#include <QString>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    void setupUI();
    void loadData();

    QLabel *nameLabel;
    QTableWidget *bookingsTable;
    QTableWidget *historyTable;
    QLabel *debtLabel;
};

#endif // MAINWINDOW_H