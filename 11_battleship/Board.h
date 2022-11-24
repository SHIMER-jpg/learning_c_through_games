#ifndef __BOARD_H__
#define __BOARD_H__
#include "./Types.h"

// Board Related
void SetupBoards(Player &player);
ShipType UpdateBoards(ShipPositionType guess, Player &currentPlayer, Player &otherPlayer);
void ClearBoards(Player &player);
void DrawBoards(const Player &player);
void DrawSeparatorLine();
void DrawShipBoardLine(const Player &player, int r);
void DrawColumnsRow();
void DrawGuessBoardLine(const Player &player, int r);
ShipPositionType GetBoardPosition();
ShipOrientationType GetShipOrientation();
ShipPositionType MapBoardPosition(char rowInput, int colInput);
bool IsValidPlacement(const Player &player, const Ship &currentShip, const ShipPositionType &position, const ShipOrientationType &orientation);
void PlaceShipOnBoard(Player &player, Ship &currentShip, ShipPositionType &position, ShipOrientationType &orientation);
char GetShipRepresentationAt(const Player &player, int row, int column);
char GetGuessRepresentationAt(const Player &player, int row, int column);
const char *GetShipNameForShipType(ShipType shipType);

#endif