#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <QMetaType>
enum GameState {WhiteTurn, BlackTurn, WhiteWin, BlackWin};

Q_DECLARE_METATYPE(GameState)

#endif // GAMESTATE_H
