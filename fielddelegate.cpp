#include "fielddelegate.h"

FieldDelegate::FieldDelegate(QObject *parent):QAbstractItemDelegate(parent)
{
    this->blackPawn = new QPixmap(":/img/res/black2.png");
    this->whitePawn = new QPixmap(":/img/res/white2.png");
    this->empty = new QPixmap(":/img/res/empty2.png");
    this->possible = new QPixmap(":/img/res/emptyh.png");

    this->widget = new QWidget();
    this->opacity = 1.0;
}

void FieldDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    painter->setOpacity(this->opacity);
    if (index.data().value<FieldState>() == WhitePawn){
        painter->drawPixmap(option.rect, *(this->whitePawn));
    }

    if (index.data().value<FieldState>() == BlackPawn){
        painter->drawPixmap(option.rect, *(this->blackPawn));
    }

    if (index.data().value<FieldState>() == Empty){
        QVariant possible = index.model()->data(index, Qt::UserRole);
        if(possible.value<bool>()){
            painter->drawPixmap(option.rect, *(this->possible));
        }else{
            painter->drawPixmap(option.rect, *(this->empty));
        }
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
        QPropertyAnimation *animation = new QPropertyAnimation(this, "opacity");
        animation->setDuration(1000);
        animation->setStartValue(1.0);
        animation->setEndValue(0.0);
        connect(animation, SIGNAL(valueChanged(QVariant)), this, SLOT(changeOpacity()));
        animation->start();
        BoardModel* bm = (BoardModel*)model;
        bm->handleMove(index.row(), index.column());
        return false;

    }else{
        return QAbstractItemDelegate::editorEvent(event, model, option, index);
    }
}

void FieldDelegate::changeOpacity()
{
}
