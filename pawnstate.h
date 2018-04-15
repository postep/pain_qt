#ifndef PAWNSTATE_H
#define PAWNSTATE_H

#include <QMetaType>
enum PawnState {Empty, WhitePawn, BlackPawn, WhiteQueen, BlackQueen, Unused};

Q_DECLARE_METATYPE(PawnState)

#endif // PAWNSTATE_H
