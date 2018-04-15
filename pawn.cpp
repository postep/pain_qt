#include "pawn.h"

Pawn::Pawn()
{
    this->state = Empty;
}

Pawn::Pawn(PawnState state)
{
    this->state = state;
}

void Pawn::paint(QPainter *painter, const QRect &rect, const QPalette &palette) const
{
    QPolygonF starPolygon;
    starPolygon << QPointF(1.0, 0.5);
    starPolygon << QPointF(0.5 + 0.5,
                           1 + 1.2);

    painter->save();
    int yOffset = (rect.height() - PaintingScaleFactor) / 2;
    painter->translate(rect.x(), rect.y() + yOffset);
    painter->scale(PaintingScaleFactor, PaintingScaleFactor);
    painter->drawPolygon(starPolygon, Qt::WindingFill);;
    painter->restore();
}

QSize Pawn::sizeHint() const
{

}

void Pawn::setState(PawnState state)
{

}

PawnState Pawn::getState(PawnState state)
{

}
