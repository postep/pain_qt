#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include <fieldstate.h>
#include <QAbstractTableModel>
#include <QVariant>
#include <QPair>
#include <Qt>
#include <QModelIndexList>
#include <gamestate.h>
#include <math.h>
#include <QObject>


class BoardModel : public QAbstractTableModel
{
Q_OBJECT

public:
    BoardModel(QObject* parent=nullptr);
    bool isBlackField(int row, int col);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    void setPossibles(int row, int col);
    void clearPossibles();
    bool havePossibles();
    void makeMove(int row, int col);
    GameState gs;
    QPair<int, int> nextLeftField(int row, int col, bool reverse);
    QPair<int, int> nextRightField(int row, int col, bool reverse);
    bool validField(QPair<int, int> f);
    FieldState oppositeTeam(FieldState fs);
    void handleMove(int row, int col);

public slots:
    void init();

signals:
    void stateChanged(GameState gs);

private:
    FieldState fields[8][8];
    bool canMove[8][8];
    bool _possibles;
    int _clickedRow, _clickedCol;
};

#endif // BOARDMODEL_H
