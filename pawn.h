#ifndef PAWN_H
#define PAWN_H

#include <QPainter>
#include <QSize>
#include <QRect>
#include <QMetaType>
#include <pawnstate.h>

class Pawn
{
public:
    Pawn();
    Pawn(PawnState state);
    void paint(QPainter *painter, const QRect &rect,
                   const QPalette &palette) const;
    QSize sizeHint() const;
    void setState(PawnState state);
    PawnState getState(PawnState state);

private:
    PawnState state;
    double PaintingScaleFactor = 1;
};

Q_DECLARE_METATYPE(Pawn)
#endif // PAWN_H
