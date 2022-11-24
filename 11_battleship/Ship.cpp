#include ".\Types.h"
#include ".\Utils.h"

void InitializeShip(Ship &ship, int shipSize, ShipType shipType);
bool IsSunk(const Player &player, const Ship &ship);
bool AreAllShipsSunk(const Player &player);

void InitializeShip(Ship &ship, int shipSize, ShipType shipType)
{
    ship.shipType = shipType;
    ship.shipSize = shipSize;
    ship.position.row = 0;
    ship.position.col = 0;
    ship.orientation = SO_HORIZONTAL;
}

bool IsSunk(const Player &player, const Ship &ship)
{
    if (ship.orientation == SO_HORIZONTAL)
    {
        for (int c = ship.position.col; c < (ship.position.col + ship.shipSize); c++)
        {
            if (player.shipBoard[ship.position.row][c].isHit == false)
            {
                return false;
            }
        }
    }
    else
    {
        for (int r = ship.position.row; r < (ship.position.row + ship.shipSize); r++)
        {
            if (player.shipBoard[r][ship.position.col].isHit == false)
            {
                return false;
            }
        }
    }

    return true;
}

bool AreAllShipsSunk(const Player &player)
{
    for (int s = 0; s < NUM_SHIPS; s++)
    {
        if (!IsSunk(player, player.ships[s]))
            return false;
    };
    return true;
}