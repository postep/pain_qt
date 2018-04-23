#include "fielddelegate.h"

FieldDelegate::FieldDelegate(QObject *parent):QAbstractItemDelegate(parent)
{
    this->blackPawn = new QPixmap(":/img/res/black2.png");
    this->whitePawn = new QPixmap(":/img/res/white2.png");
    this->empty = new QPixmap(":/img/res/empty2.png");
    this->possible = new QPixmap(":/img/res/emptyh.png");

    this->widget = new QWidget();
}

void FieldDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    if (index.data().value<FieldState>() == WhitePawn){
        painter->drawPixmap(option.rect, *(this->whitePawn));
    }

    if (index.data().value<FieldState>() == BlackPawn){
        painter->drawPixmap(option.rect, *(this->blackPawn));
    }

    if (index.data().value<FieldState>() == Empty){
        painter->drawPixmap(option.rect, *(this->empty));
    }
    painter->restore();
}

QSize FieldDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{

}

QWidget *FieldDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return this->widget;
}

void FieldDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{

}

void FieldDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{

}

bool FieldDelegate::event(QEvent *event)
{
    return QAbstractItemDelegate::event(event);
}

bool FieldDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    int e = event->type();
    if (e == QEvent::MouseButtonPress){
        //wyliczenie ktore pola do ruszenia
        return false;
    }else if (e == QEvent::MouseButtonRelease){
        //usuniecie z modelu
        return false;
    }else{
        return QAbstractItemDelegate::editorEvent(event, model, option, index);
    }
}
