#ifndef PAWNDELEGATE_H
#define PAWNDELEGATE_H

#include <QStyledItemDelegate>
#include <pawn.h>

class PawnDelegate : public QStyledItemDelegate
{
public:
    PawnDelegate(QWidget *parent = 0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const override;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;

private slots:
    void commitAndCloseEditor();
};


#endif // PAWNDELEGATE_H
