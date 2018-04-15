#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->board = new BoardModel(this);
    this->pawnDelegate = new PawnDelegate(this);

    ui->setupUi(this);

    ui->boardView->setModel(this->board);
    for(int i=0; i < ui->boardView->model()->rowCount(); i++){
        ui->boardView->setItemDelegateForRow(i, this->pawnDelegate);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
