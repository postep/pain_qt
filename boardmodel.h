#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include <fieldstate.h>
#include <QAbstractTableModel>
#include <QVariant>
#include <QPair>

class BoardModel : public QAbstractTableModel
{
public:
    BoardModel(QObject* parent=nullptr);
    bool isBlackField(int row, int col);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

private:
    FieldState fields[8][8];
    bool canMove[8][8];
};

#endif // BOARDMODEL_H
