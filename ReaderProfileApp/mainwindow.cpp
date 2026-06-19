#include "mainwindow.h"
#include <QHeaderView>
#include <QWidget>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    loadData();
}

void MainWindow::setupUI()
{
    // Создаём центральный виджет
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setSpacing(15);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    // ===== ЗАГОЛОВОК =====
    QLabel *headerLabel = new QLabel("Личный кабинет: Иванов Иван Иванович", this);
    QFont headerFont = headerLabel->font();
    headerFont.setPointSize(14);
    headerFont.setBold(true);
    headerLabel->setFont(headerFont);
    headerLabel->setStyleSheet("background-color: #2c3e50; color: white; padding: 10px; border-radius: 5px;");
    headerLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(headerLabel);

    // ===== ТЕКУЩИЕ БРОНИРОВАНИЯ =====
    QLabel *bookingsTitle = new QLabel("📌 Текущие бронирования:", this);
    QFont titleFont = bookingsTitle->font();
    titleFont.setPointSize(12);
    titleFont.setBold(true);
    bookingsTitle->setFont(titleFont);
    mainLayout->addWidget(bookingsTitle);

    // Таблица бронирований
    bookingsTable = new QTableWidget(0, 3, this);
    bookingsTable->setHorizontalHeaderLabels({"Книга", "Срок до", "Статус"});
    bookingsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    bookingsTable->setAlternatingRowColors(true);
    bookingsTable->setStyleSheet(
        "QTableWidget { background-color: #ffffff; gridline-color: #cccccc; }"
        "QTableWidget::item { padding: 5px; }"
        );
    mainLayout->addWidget(bookingsTable);

    // ===== ИСТОРИЯ ВЫДАЧ =====
    QLabel *historyTitle = new QLabel("📚 История выдач (последние 3):", this);
    historyTitle->setFont(titleFont);
    mainLayout->addWidget(historyTitle);

    // Таблица истории
    historyTable = new QTableWidget(0, 3, this);
    historyTable->setHorizontalHeaderLabels({"Книга", "Дата выдачи", "Дата возврата"});
    historyTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    historyTable->setAlternatingRowColors(true);
    historyTable->setStyleSheet(
        "QTableWidget { background-color: #ffffff; gridline-color: #cccccc; }"
        "QTableWidget::item { padding: 5px; }"
        );
    mainLayout->addWidget(historyTable);

    // ===== ЗАДОЛЖЕННОСТИ =====
    QLabel *debtTitle = new QLabel("⚠️ Задолженности:", this);
    debtTitle->setFont(titleFont);
    debtTitle->setStyleSheet("color: #e67e22;");
    mainLayout->addWidget(debtTitle);

    debtLabel = new QLabel("Нет задолженностей. Спасибо, что вовремя возвращаете книги!", this);
    debtLabel->setStyleSheet("color: #27ae60; font-weight: bold; padding: 5px; background-color: #eafaf1; border-radius: 3px;");
    debtLabel->setWordWrap(true);
    mainLayout->addWidget(debtLabel);

    // Устанавливаем центральный виджет
    setCentralWidget(centralWidget);
}

void MainWindow::loadData()
{
    // ===== ЗАПОЛНЯЕМ ТАБЛИЦУ БРОНИРОВАНИЙ =====
    bookingsTable->insertRow(0);
    bookingsTable->setItem(0, 0, new QTableWidgetItem("«1984» - Джордж Оруэлл"));
    bookingsTable->setItem(0, 1, new QTableWidgetItem("25.05.2026"));
    bookingsTable->setItem(0, 2, new QTableWidgetItem("Готово к выдаче"));
    // Делаем статус зелёным
    bookingsTable->item(0, 2)->setForeground(QColor(39, 174, 96));

    bookingsTable->insertRow(1);
    bookingsTable->setItem(1, 0, new QTableWidgetItem("«Мастер и Маргарита» - М. Булгаков"));
    bookingsTable->setItem(1, 1, new QTableWidgetItem("01.06.2026"));
    bookingsTable->setItem(1, 2, new QTableWidgetItem("Ожидает подтверждения"));
    // Делаем статус оранжевым
    bookingsTable->item(1, 2)->setForeground(QColor(230, 126, 34));

    // ===== ЗАПОЛНЯЕМ ТАБЛИЦУ ИСТОРИИ =====
    historyTable->insertRow(0);
    historyTable->setItem(0, 0, new QTableWidgetItem("«Война и мир» - Л. Толстой"));
    historyTable->setItem(0, 1, new QTableWidgetItem("01.03.2026"));
    historyTable->setItem(0, 2, new QTableWidgetItem("20.03.2026"));

    historyTable->insertRow(1);
    historyTable->setItem(1, 0, new QTableWidgetItem("«Преступление и наказание» - Ф. Достоевский"));
    historyTable->setItem(1, 1, new QTableWidgetItem("10.02.2026"));
    historyTable->setItem(1, 2, new QTableWidgetItem("28.02.2026"));

    // ===== ЗАДОЛЖЕННОСТИ =====
    debtLabel->setText("Нет задолженностей. Спасибо, что вовремя возвращаете книги!");
}