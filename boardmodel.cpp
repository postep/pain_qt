#include "boardmodel.h"

BoardModel::BoardModel(QObject *parent):QStandardItemModel(8, 8, parent)
{
    QStringList horizontalHeaders;
    horizontalHeaders << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8";
    this->setHorizontalHeaderLabels(horizontalHeaders);

    QStringList verticalHeaders;
    verticalHeaders << "A" << "B" << "C" << "D" << "E" << "F" << "G" << "H";
    this->setVerticalHeaderLabels(verticalHeaders);

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if (i <= 2 && this->isBlackField(i, j)){
                this->setData(this->index(i, j), WhitePawn);
            } else if (i >= 6 && this->isBlackField(i, j)){
                this->setData(this->index(i, j), BlackPawn);
            } else{
                this->setData(this->index(i, j), Empty);
            }
        }
    }
}

bool BoardModel::isBlackField(int row, int col)
{
    return (row + col) % 2 == 0;
}
