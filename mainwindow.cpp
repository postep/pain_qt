#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->board = new BoardModel(this);
    this->delegate = new FieldDelegate(this);

    ui->setupUi(this);
    ui->gridLayout->removeWidget(ui->boardView);
    ui->boardView->deleteLater();
    ui->boardView = new BoardView(this);
    ui->gridLayout->addWidget(ui->boardView, 0, 0);

    ui->boardView->setModel(this->board);
    ui->boardView->setItemDelegate(this->delegate);

    connect(ui->pushButton, SIGNAL(clicked(bool)), this->board, SLOT(init()));
    connect(this->board, SIGNAL(stateChanged(GameState)), this, SLOT(onGameStateChange(GameState)));
    this->board->init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onGameStateChange(GameState gs)
{
    if(gs == WhiteTurn){
        ui->label->setText("Ruch białych");
    }
    if(gs == BlackTurn){
        ui->label->setText("Ruch czarnych");
    }
    if(gs == BlackWin){
        ui->label->setText("Wygrana czarnych");
    }
    if(gs == WhiteWin){
        ui->label->setText("Wygrana białych");
    }
}



void MainWindow::on_actionUstawienia_triggered()
{
    ui->label->setVisible(!ui->label->isVisible());
}

void MainWindow::on_actionZamknij_triggered()
{
    this->deleteLater();
}
