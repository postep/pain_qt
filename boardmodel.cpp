#include "boardmodel.h"

BoardModel::BoardModel(QObject *parent):QAbstractTableModel(parent)
{
    init();
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
    if(role == Qt::DisplayRole){
        QVariant v = QVariant::fromValue(this->fields[index.row()][index.column()]);
        return v;
    }

    if(role == Qt::UserRole){
        QVariant v = QVariant::fromValue(this->canMove[index.row()][index.column()]);
        return v;
    }
}

bool BoardModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return false;
}

void BoardModel::setPossibles(int row, int col)
{
    for(int r = 0; r < 8; r++){
        for(int c = 0; c < 8; c++){
            this->canMove[r][c] = false;
        }
    }

    if((this->fields[row][col] == WhitePawn && this->gs == WhiteTurn)||(this->fields[row][col] == BlackPawn && this->gs == BlackTurn)){
        QPair<int, int> nl = nextLeftField(row, col, false);
        QPair<int, int> nr = nextRightField(row, col, false);
        if(validField(nl)){
            if(this->fields[nl.first][nl.second] == Empty){
                this->canMove[nl.first][nl.second] = true;
                this->_possibles = true;
            }else if(this->fields[nl.first][nl.second] == this->oppositeTeam(this->fields[row][col])){
                QPair<int, int> nnl = this->nextLeftField(nl.first, nl.second, true);
                if(validField(nnl) && this->fields[nnl.first][nnl.second] == Empty){
                    this->canMove[nnl.first][nnl.second] = true;
                    this->_possibles = true;
                }
            }
        }
        if(validField(nr)){
            if(this->fields[nr.first][nr.second] == Empty){
                this->canMove[nr.first][nr.second] = true;
                this->_possibles = true;

            }else if(this->fields[nr.first][nr.second] == this->oppositeTeam(this->fields[row][col])){
                QPair<int, int> nnr = this->nextRightField(nr.first, nr.second, true);
                if(validField(nnr) && this->fields[nnr.first][nnr.second] == Empty){
                    this->canMove[nnr.first][nnr.second] = true;
                    this->_possibles = true;
                }
            }
        }
    }
    emit this->dataChanged(this->index(0, 0), this->index(7, 7));
}

void BoardModel::clearPossibles()
{
    for(int r = 0; r < 8; r++){
        for(int c = 0; c < 8; c++){
            this->canMove[r][c] = false;
        }
    }
    this->_possibles = false;
    emit this->dataChanged(this->index(0, 0), this->index(7, 7));
}

bool BoardModel::havePossibles()
{
    return this->_possibles;
}

void BoardModel::makeMove(int row, int col)
{
    if(abs(_clickedCol-col) == 2 && abs(_clickedRow-row)){
        int betweenRow = abs((_clickedRow+row)/2);
        int betweenCol = abs((_clickedCol+col)/2);
        this->fields[betweenRow][betweenCol] = Empty;
    }
    this->fields[row][col] = this->fields[this->_clickedRow][this->_clickedCol];
    this->fields[this->_clickedRow][this->_clickedCol] = Empty;
    for(int r = 0; r < 8; r++){
        for(int c = 0; c < 8; c++){
            this->canMove[r][c] = false;
        }
    }
    this->_possibles = false;
    if(this->gs == WhiteTurn){
        if(row == 0){
            this->gs = WhiteWin;
        }else{
            this->gs = BlackTurn;
        }
    }else if(this->gs == BlackTurn){
        if(row == 7){
            this->gs = BlackWin;
        }else{
            this->gs = WhiteTurn;
        }
    }
    emit this->stateChanged(this->gs);
    emit this->dataChanged(this->index(0, 0), this->index(7, 7));
}

QPair<int, int> BoardModel::nextLeftField(int row, int col, bool reverse)
{
    if((this->fields[row][col] == WhitePawn && !reverse)||(this->fields[row][col] == BlackPawn && reverse)){
        return QPair<int, int>(row-1, col-1);
    }else if((this->fields[row][col] == BlackPawn && !reverse)||(this->fields[row][col] == WhitePawn && reverse)){
        return QPair<int, int>(row+1, col-1);
    }
}

QPair<int, int> BoardModel::nextRightField(int row, int col, bool reverse)
{
    if((this->fields[row][col] == WhitePawn && !reverse)||(this->fields[row][col] == BlackPawn && reverse)){
        return QPair<int, int>(row-1, col+1);
    }else if((this->fields[row][col] == BlackPawn && !reverse)||(this->fields[row][col] == WhitePawn && reverse)){
        return QPair<int, int>(row+1, col+1);
    }
}

bool BoardModel::validField(QPair<int, int> f)
{
    return (f.first < 8 && f.first >=0 && f.second < 8 && f.second >= 0);
}

FieldState BoardModel::oppositeTeam(FieldState fs)
{
    if(fs == WhitePawn){
        return BlackPawn;
    }
    if(fs == BlackPawn){
        return WhitePawn;
    }
}

void BoardModel::handleMove(int row, int col)
{
    if(this->fields[row][col] == Empty && this->canMove[row][col]){
        this->makeMove(row, col);
    }else{
        this->setPossibles(row, col);
        this->_clickedCol = col;
        this->_clickedRow = row;
    }
}

void BoardModel::init()
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

    this->_possibles = false;
    this->gs = WhiteTurn;
    emit dataChanged(this->index(0, 0), this->index(7, 7));
    emit stateChanged(this->gs);
}



