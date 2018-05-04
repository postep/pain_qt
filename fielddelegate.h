#ifndef FIELDDELEGATE_H
#define FIELDDELEGATE_H

#include <QAbstractItemDelegate>
#include <QPainter>
#include <QDebug>
#include <QEvent>
#include <fieldstate.h>
#include <boardmodel.h>
#include <QPropertyAnimation>

class FieldDelegate : public QAbstractItemDelegate
{
    Q_OBJECT
public:
    FieldDelegate(QObject *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const override;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;

    bool event(QEvent *event);

    bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

public slots:
    void changeOpacity();
private:
    QPixmap *blackPawn;
    QPixmap *whitePawn;
    QPixmap *empty;
    QPixmap *possible;
    QWidget *widget;

    float opacity;
};

#endif // FIELDDELEGATE_H
