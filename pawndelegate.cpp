#include "pawndelegate.h"

PawnDelegate::PawnDelegate(QWidget *parent) : QStyledItemDelegate(parent)
{

}



void PawnDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.data().canConvert<Pawn>()){
        Pawn pawn = qvariant_cast<Pawn>(index.data());
        pawn.paint(painter, option.rect, option.palette);
    }else{
        QStyledItemDelegate::paint(painter, option, index);
    }
}

QSize PawnDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{

}

QWidget *PawnDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

}

void PawnDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{

}

void PawnDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{

}

void PawnDelegate::commitAndCloseEditor()
{

}
