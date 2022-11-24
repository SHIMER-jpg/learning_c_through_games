#include <iostream>
#include <cctype>
#include <cstring>
#include <stdlib.h>
#include ".\Types.h"
#include ".\Utils.h"
#include ".\Board.h"
#include ".\Ship.h"

const char *INPUT_ERROR_STRING = "Please select a valid input";

// Game Related
void PlayGame(Player &player1, Player &player2);
bool WantsToPlayAgain();
void InitializePlayer(Player &player, const char *playerName);
void SwitchPlayer(Player **currentPlayer, Player **otherPlayer);
bool IsGameOver(const Player &player1, const Player &player2);
void DisplayWinner(const Player &player1, const Player &player2);

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

    return 0;
}

void InitializePlayer(Player &player, const char *playerName)
{
    if (playerName != nullptr && strlen(playerName) > 0)
    {
        strcpy(player.playerName, playerName);
    }
    InitializeShip(player.ships[4], SUBMARINE_SIZE, ST_SUBMARINE);
    InitializeShip(player.ships[3], DESTROYER_SIZE, ST_DESTROYER);
    InitializeShip(player.ships[2], CRUISER_SIZE, ST_CRUISER);
    InitializeShip(player.ships[1], BATTLESHIP_SIZE, ST_BATTLESHIP);
    InitializeShip(player.ships[0], AIRCRAFT_CARRIER_SIZE, ST_AIRCRAFT_CARRIER);
}

void PlayGame(Player &player1, Player &player2)
{
    ClearScreen();
    SetupBoards(player1);
    SetupBoards(player2);

    Player *currentPlayer = &player1;
    Player *otherPlayer = &player2;

    do
    {
        DrawBoards(*currentPlayer);
        bool isValidGuess = false;
        ShipPositionType guess;
        std::cout << currentPlayer->playerName << "'s Turn" << std::endl;
        do
        {
            std::cout << currentPlayer->playerName << " what is your guess? " << std::endl;

            guess = GetBoardPosition();

            std::cout << "\033[1;31m[DEBUG]: VALID GUESS " << &guess
                      << "\033[0m\n"
                      << std::endl;

            isValidGuess = currentPlayer->guessBoard[guess.row][guess.col] == GT_NONE;

            if (!isValidGuess)
            {
                std::cout << "That was not a valid guess! Please try again" << std::endl;
            }

        } while (!isValidGuess);

        ShipType type = UpdateBoards(guess, *currentPlayer, *otherPlayer);

        DrawBoards(*currentPlayer);
        if (type != ST_NONE && IsSunk(*otherPlayer, otherPlayer->ships[type - 1]))
        {
            std::cout << "You sunk " << otherPlayer->playerName << "'s " << GetShipNameForShipType(type) << " !" << std::endl;
        }
        SwitchPlayer(&currentPlayer, &otherPlayer);
        WaitForKeyPress();

    } while (!IsGameOver(player1, player2));

    DisplayWinner(player1, player2);
    WaitForKeyPress();
}

bool IsGameOver(const Player &player1, const Player &player2)
{
    return AreAllShipsSunk(player1) || AreAllShipsSunk(player2);
}

void DisplayWinner(const Player &player1, const Player &player2)
{
    if (AreAllShipsSunk(player1))
    {
        std::cout << player2.playerName << " Won!" << std::endl;
    }
    else
    {
        std::cout << player1.playerName << " Won!" << std::endl;
    }
}
void SwitchPlayer(Player **currentPlayer, Player **otherPlayer)
{
    Player *aux = *currentPlayer;
    *currentPlayer = *otherPlayer;
    *otherPlayer = aux;
}

bool WantsToPlayAgain()
{
    char input;
    const char validInput[2] = {'y', 'n'};
    input = GetCharacter("Do you want to play again? (y/n): ", INPUT_ERROR_STRING, validInput, 2, CC_LOWER_CASE);
    return input == 'y';
}
