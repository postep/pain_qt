#include "boardview.h"

BoardView::BoardView(QWidget* parent):QTableView(parent)
{

}

void BoardView::paintEvent(QPaintEvent *e)
{
    QTableView::paintEvent(e);
}
