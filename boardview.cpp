#include "boardview.h"

BoardView::BoardView(QWidget* parent):QTableView(parent)
{
    //this->setStyleSheet("QHeaderView { background: rgb(255, 255, 127); }");
    this->setShowGrid(false);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void BoardView::paintEvent(QPaintEvent *e)
{
    int diff = (e->rect().width() < e->rect().height()) ? e->rect().width() : e->rect().height();
    for(int i = 0; i < 8; i++){
        this->setColumnWidth(i, (diff)/8);
        this->setRowHeight(i, (diff)/8);
    }
    QTableView::paintEvent(e);
}
