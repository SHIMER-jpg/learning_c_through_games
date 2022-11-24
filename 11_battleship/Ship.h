#ifndef __SHIP_H__
#define __SHIP_H__
#include "./Types.h"

// Ship related
void InitializeShip(Ship &ship, int shipSize, ShipType shipType);
bool IsSunk(const Player &player, const Ship &ship);
bool AreAllShipsSunk(const Player &player);

#endif