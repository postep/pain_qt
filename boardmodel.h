#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include <fieldstate.h>
#include <QAbstractTableModel>
#include <QVariant>
#include <QPair>
#include <Qt>
#include <QModelIndexList>
#include <QMimeData>
#include <QIODevice>
#include <QDataStream>


class BoardModel : public QAbstractTableModel
{
public:
    BoardModel(QObject* parent=nullptr);
    bool isBlackField(int row, int col);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::DropActions supportedDropActions() const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);
    QMimeData *mimeData(const QModelIndexList &indexes) const;
    QStringList mimeTypes() const;
    QHash<int, QByteArray> roleNames();

private:
    FieldState fields[8][8];
    bool canMove[8][8];
};

#endif // BOARDMODEL_H
