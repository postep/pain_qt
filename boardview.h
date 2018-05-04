#ifndef BOARDVIEW_H
#define BOARDVIEW_H

#include <QTableView>
#include <QPaintEvent>
#include <QWidget>

class BoardView : public QTableView
{
public:
    BoardView(QWidget* parent=nullptr);
    void paintEvent(QPaintEvent *e);
};

#endif // BOARDVIEW_H
