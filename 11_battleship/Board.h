#ifndef __BOARD_H__
#define __BOARD_H__
#include "./Types.h"

// Board Related
void SetupBoards(Player &player);
void ClearBoards(Player &player);
void DrawBoards(const Player &player);
void DrawSeparatorLine();
void DrawShipBoardLine(const Player &player, int r);
void DrawColumnsRow();
void DrawGuessBoardLine(const Player &player, int r);
char GetShipRepresentationAt(const Player &player, int row, int column);
char GetGuessRepresentationAt(const Player &player, int row, int column);

#endif