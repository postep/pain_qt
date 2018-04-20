#include "fielddelegate.h"

FieldDelegate::FieldDelegate(QObject *parent):QAbstractItemDelegate(parent)
{
    this->blackPawn = new QPixmap(":/img/res/black.jpg");
}

void FieldDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    QRect r = QRect();
    painter->drawPixmap(option.rect, *(this->blackPawn));
    painter->restore();
}

QSize FieldDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{

}

QWidget *FieldDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

}

void FieldDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{

}

void FieldDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{

}
