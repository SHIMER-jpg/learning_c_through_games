#include <iostream>
#include <cctype>
#include <cstring>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
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
PlayerType GetPlayer2Type();
ShipPositionType GetAiGuess(const Player &aiPlayer);

int main()
{

    srand(time(NULL));
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

PlayerType GetPlayer2Type()
{
    const int validInputs[2] = {1, 2};

    int input = GetInteger("Who would you like to player against?\n1. Human\n2. AI\n\nWhat is your choice? ", INPUT_ERROR_STRING, validInputs, 2);

    if (input == 1)
    {
        return PT_HUMAN;
    }
    else
    {
        return PT_AI;
    }
}

void PlayGame(Player &player1, Player &player2)
{
    ClearScreen();
    player1.playerType = PT_HUMAN;
    player2.playerType = GetPlayer2Type();

    SetupBoards(player1);
    SetupBoards(player2);

    Player *currentPlayer = &player1;
    Player *otherPlayer = &player2;

    do
    {
        if (currentPlayer->playerType == PT_HUMAN)
            DrawBoards(*currentPlayer);
        bool isValidGuess = false;
        ShipPositionType guess;
        std::cout << currentPlayer->playerName << "'s Turn" << std::endl;
        do
        {
            if (currentPlayer->playerType == PT_HUMAN)
            {
                std::cout << currentPlayer->playerName << " what is your guess? " << std::endl;
                guess = GetBoardPosition();
            }
            else
            {
                guess = GetAiGuess(*currentPlayer);
            }

            isValidGuess = currentPlayer->guessBoard[guess.row][guess.col] == GT_NONE;

            if (!isValidGuess && currentPlayer->playerType == PT_HUMAN)
            {
                std::cout << "That was not a valid guess! Please try again" << std::endl;
            }

        } while (!isValidGuess);

        ShipType type = UpdateBoards(guess, *currentPlayer, *otherPlayer);

        if (currentPlayer->playerType == PT_AI)
        {
            DrawBoards(*otherPlayer);
            std::cout << currentPlayer->playerName << " chose row " << char(guess.row + 'A') << " and column " << guess.col << std::endl;
        }
        else
            DrawBoards(*currentPlayer);

        if (type != ST_NONE && IsSunk(*otherPlayer, otherPlayer->ships[type - 1]))
        {
            if (currentPlayer->playerType == PT_AI)
            {
                std::cout << currentPlayer->playerName << " sunk your" << GetShipNameForShipType(type) << " !" << std::endl;
            }
            else
            {
                std::cout << "You sunk " << otherPlayer->playerName << "'s " << GetShipNameForShipType(type) << " !" << std::endl;
            }
        };
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

ShipPositionType GetAiGuess(const Player &aiPlayer)
{
    ShipPositionType guess;
    guess.row = rand() % BOARD_SIZE;
    guess.col = rand() % BOARD_SIZE;
    return guess;
}