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
            if (this->isBlackField(i, j)){
                if(i <= 2){
                    this->setData(this->index(i, j), QVariant::fromValue(Pawn(PawnState::WhitePawn)));
                }else if (i >= 6){
                    this->setData(this->index(i, j), QVariant::fromValue(Pawn(PawnState::BlackPawn)));
                }else{
                    this->setData(this->index(i, j), QVariant::fromValue(Pawn(PawnState::Empty)));
                }
            }else{
                this->setData(this->index(i, j), QVariant::fromValue(Pawn(PawnState::Unused)));
            }

        }
    }
}

bool BoardModel::isBlackField(int row, int col)
{
    return (row + col) % 2 == 0;
}
