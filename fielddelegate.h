#ifndef FIELDDELEGATE_H
#define FIELDDELEGATE_H

#include <QAbstractItemDelegate>
#include <QPainter>

class FieldDelegate : public QAbstractItemDelegate
{
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

private:
    QPixmap *blackPawn;
};

#endif // FIELDDELEGATE_H
