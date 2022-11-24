
#ifndef __TYPES_H__
#define __TYPES_H__

enum
{
    AIRCRAFT_CARRIER_SIZE = 5,
    BATTLESHIP_SIZE = 4,
    CRUISER_SIZE = 3,
    DESTROYER_SIZE = 3,
    SUBMARINE_SIZE = 2,
    BOARD_SIZE = 10,
    NUM_SHIPS = 5,
    PLAYER_NAME_SIZE = 8,
    MAX_SHIP_SIZE = AIRCRAFT_CARRIER_SIZE
};

enum ShipType
{
    ST_NONE = 0,
    ST_AIRCRAFT_CARRIER,
    ST_BATTLESHIP,
    ST_CRUISER,
    ST_DESTROYER,
    ST_SUBMARINE
};

enum ShipOrientationType
{
    SO_HORIZONTAL = 0,
    SO_VERTICAL = 1,
};

struct ShipPositionType
{
    int row;
    int col;
};

struct Ship
{
    ShipType shipType;
    int shipSize;
    ShipOrientationType orientation;
    ShipPositionType position;
};

enum GuessType
{
    GT_NONE = 0,
    GT_HIT,
    GT_MISSED
};

struct ShipPartType
{
    ShipType shipType;
    bool isHit;
};

struct Player
{
    char playerName[PLAYER_NAME_SIZE];
    Ship ships[NUM_SHIPS];
    GuessType guessBoard[BOARD_SIZE][BOARD_SIZE];
    ShipPartType shipBoard[BOARD_SIZE][BOARD_SIZE];
};

#endif