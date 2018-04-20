#include "boardmodel.h"

BoardModel::BoardModel(QObject *parent):QAbstractTableModel(parent)
{
    for (int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            this->fields[i][j] = Unused;
            this->canMove[i][j] = false;
        }
    }
}

bool BoardModel::isBlackField(int row, int col)
{
    return (row + col) % 2 == 0;
}

int BoardModel::rowCount(const QModelIndex &parent) const
{
    return 8;
}

int BoardModel::columnCount(const QModelIndex &parent) const
{
    return 8;
}

QVariant BoardModel::data(const QModelIndex &index, int role) const
{
    return QVariant::fromValue(QPair<FieldState, bool>(this->fields[index.row()][index.column()],
            this->canMove[index.row()][index.column()]));
}

bool BoardModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.row() < 8 && index.column() < 8){
        QPair<FieldState, bool> v = value.value<QPair<FieldState, bool>>();
        this->fields[index.row()][index.column()] = v.first;
        this->canMove[index.row()][index.column()] = v.second;
        return true;
    }else{
        return false;
    }
}
