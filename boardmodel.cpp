#include "boardmodel.h"

BoardModel::BoardModel(QObject *parent):QAbstractTableModel(parent)
{
    for (int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            if((i+j) % 2 == 0 && i < 3){
                this->fields[i][j] = BlackPawn;
            }else if((i+j) % 2 == 0 && i > 4){
                this->fields[i][j] = WhitePawn;
            }else if((i+j) % 2 == 0){
                this->fields[i][j] = Empty;
            }else{
                this->fields[i][j] = Unused;
            }

            this->canMove[i][j] = false;
        }
    }

    this->roleNames();
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
    QVariant v = QVariant::fromValue(this->fields[index.row()][index.column()]);
    return v;
}

bool BoardModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return false;
}

Qt::DropActions BoardModel::supportedDropActions() const
{
    return Qt::CopyAction | Qt::MoveAction;
}

Qt::ItemFlags BoardModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags defaultFlags = QAbstractItemModel::flags(index);

    if (index.isValid())
        return Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | defaultFlags;
    else
        return Qt::ItemIsDropEnabled | defaultFlags;
}

bool BoardModel::dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent)
{
    QByteArray encodedData = data->data("field");
    QDataStream stream(&encodedData, QIODevice::ReadOnly);
    while (!stream.atEnd()) {
        QString text;
        stream >> text;
        FieldState fs = (FieldState)(text.toInt());
        if(fs == WhitePawn || fs == BlackPawn){
            QVariant v = QVariant::fromValue<FieldState>(fs);
            this->setData(QModelIndex(), v, Qt::DisplayRole);
        }
    }
}

QMimeData *BoardModel::mimeData(const QModelIndexList &indexes) const
{
    QMimeData *mime = new QMimeData();
    QByteArray encodedData;

    QDataStream stream(&encodedData, QIODevice::WriteOnly);

    foreach (QModelIndex index, indexes) {
        if (index.isValid()) {
            QVariant v = data(index, Qt::DisplayRole);
            FieldState fs = v.value<FieldState>();
            QString s = QString::number((int)fs);
            stream << s;
        }
    }

    mime->setData("field", encodedData);
    return mime;
}

QStringList BoardModel::mimeTypes() const
{
    QStringList types;
    types << "field";
    return types;
}

QHash<int, QByteArray> BoardModel::roleNames()
{
    QHash<int, QByteArray> r = QAbstractItemModel::roleNames();
    r.insert(Qt::UserRole+1, "MovePossible");
    int i=0;
    i++;
    return r;
}

