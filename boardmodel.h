#ifndef BOARDMODEL_H
#define BOARDMODEL_H


#include <QStandardItemModel>
#include <pawndelegate.h>
#include <QVariant>

class BoardModel : public QStandardItemModel
{
public:
    BoardModel(QObject* parent=nullptr);
    bool isBlackField(int row, int col);

};

#endif // BOARDMODEL_H
