#include <iostream>
#include <cctype>
#include <cstring>
#include <stdlib.h>
#include ".\Utils.h"
#include ".\Board.h"
#include ".\Types.h"

const char *INPUT_ERROR_STRING = "Please select a valid input";

// Game Related
void PlayGame(Player &player1, Player &player2);
bool WantsToPlayAgain();
void InitializePlayer(Player &player, const char *playerName);
void InitializeShip(Ship &ship, int shipSize, ShipType shipType);

int main()
{

    Player player1;
    Player player2;

    InitializePlayer(player1, "Player 1");
    InitializePlayer(player2, "Player 2");

    do
    {
        PlayGame(player1, player2);
    } while (WantsToPlayAgain());
    // } while (false);

    return 0;
}

void InitializePlayer(Player &player, const char *playerName)
{
    if (playerName != nullptr && strlen(playerName) > 0)
    {
        strcpy(player.playerName, playerName);
    }
    InitializeShip(player.ships[0], AIRCRAFT_CARRIER_SIZE, ST_AIRCRAFT_CARRIER);
    InitializeShip(player.ships[1], BATTLESHIP_SIZE, ST_BATTLESHIP);
    InitializeShip(player.ships[2], CRUISER_SIZE, ST_CRUISER);
    InitializeShip(player.ships[3], DESTROYER_SIZE, ST_DESTROYER);
    InitializeShip(player.ships[4], SUBMARINE_SIZE, ST_SUBMARINE);
}

void InitializeShip(Ship &ship, int shipSize, ShipType shipType)
{
    ship.shipType = shipType;
    ship.shipSize = shipSize;
    ship.position.row = 0;
    ship.position.col = 0;
    ship.orientation = SO_HORIZONTAL;
}

void PlayGame(Player &player1, Player &player2)
{
    SetupBoards(player1);
    SetupBoards(player2);
}

bool WantsToPlayAgain()
{
    char input;
    const char validInput[2] = {'y', 'n'};
    input = GetCharacter("Do you want to play again? (y/n): ", INPUT_ERROR_STRING, validInput, 2, CC_LOWER_CASE);
    return input == 'y';
}
