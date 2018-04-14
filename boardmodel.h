#ifndef BOARDMODEL_H
#define BOARDMODEL_H


#include <QStandardItemModel>

class BoardModel : public QStandardItemModel
{
public:
    BoardModel(QObject* parent=nullptr);
    bool isBlackField(int row, int col);

    enum FIELD {Empty, WhitePawn, BlackPawn};
};

#endif // BOARDMODEL_H
