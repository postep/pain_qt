#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->board = new BoardModel(this);
    this->delegate = new FieldDelegate(this);

    ui->setupUi(this);
    //ui->verticalLayout->removeWidget(ui->boardView);
    //ui->boardView->deleteLater();
    //ui->boardView = new BoardView(this);
    //ui->verticalLayout->addWidget(ui->boardView);

    ui->boardView->setModel(this->board);
    ui->boardView->setItemDelegate(this->delegate);
    ui->boardView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->boardView->setDragEnabled(true);
    ui->boardView->setAcceptDrops(true);
    ui->boardView->setDropIndicatorShown(true);
    for(int i = 0; i < ui->boardView->horizontalHeader()->count(); ++i){
        ui->boardView->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }
    for(int i = 0; i < ui->boardView->verticalHeader()->count(); ++i){
        ui->boardView->verticalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
