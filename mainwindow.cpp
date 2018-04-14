#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->board = new BoardModel(this);

    ui->setupUi(this);

    ui->boardView->setModel(this->board);
}

MainWindow::~MainWindow()
{
    delete ui;
}
