#include <iostream>
#include ".\Types.h"
#include ".\Utils.h"

void SetupBoards(Player &player);
void ClearBoards(Player &player);
void DrawBoards(const Player &player);
void DrawSeparatorLine();
void DrawShipBoardLine(const Player &player, int r);
void DrawColumnsRow();
void DrawGuessBoardLine(const Player &player, int r);
ShipPositionType GetBoardPosition();
char GetShipRepresentationAt(const Player &player, int row, int column);
char GetGuessRepresentationAt(const Player &player, int row, int column);
const char *GetShipNameForShipType(ShipType shipType);

void SetupBoards(Player &player)
{
    ClearBoards(player);
    for (int i = 0; i < NUM_SHIPS; i++)
    {
        DrawBoards(player);
        Ship &currentShip = player.ships[i];
        ShipPositionType position;
        ShipOrientationType orientation;
        bool isValidPlacement = false;
        do
        {
            std::cout << player.playerName << " set position and orientation for your " << GetShipNameForShipType(currentShip.shipType) << std::endl;
            position = GetBoardPosition();

        } while (!isValidPlacement);
    }
}
ShipPositionType GetBoardPosition()
{
    char rowInput;
    int colInput;
    const char validRowInputs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    const int validColumnInput[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    rowInput = GetCharacter("Please input a row (A - J): ", INPUT_ERROR_STRING, validRowInputs, 10, CC_UPPER_CASE);
    colInput = GetCharacter("Please input a column (1 - 10): ", INPUT_ERROR_STRING, validColumnInput, 10, CC_EITHER);
}

void ClearBoards(Player &player)
{
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            player.guessBoard[r][j] = GT_NONE;
            player.shipBoard[r][j].shipType = ST_NONE;
            player.shipBoard[r][j].isHit = false;
        }
    }
}

void DrawBoards(const Player &player)
{
    // system("CLS");
    DrawColumnsRow();
    DrawColumnsRow();
    std::cout << std::endl;

    for (int r = 0; r < BOARD_SIZE; r++)
    {
        DrawSeparatorLine();
        std::cout << " ";
        DrawSeparatorLine();
        std::cout << " " << std::endl;
        DrawShipBoardLine(player, r);
        std::cout << " ";
        DrawGuessBoardLine(player, r);
        std::cout << " " << std::endl;
    }

    DrawSeparatorLine();
    std::cout << " ";
    DrawSeparatorLine();
    std::cout << " " << std::endl;
}

void DrawSeparatorLine()
{
    std::cout << " ";
    for (int c = 0; c < BOARD_SIZE; c++)
    {
        std::cout << "+---";
    }
    std::cout << "+";
}

void DrawShipBoardLine(const Player &player, int r)
{
    char rowName = r + 'A';
    std::cout << rowName << "|";
    for (int c = 0; c < BOARD_SIZE; c++)
    {
        std::cout << " "
                  << GetShipRepresentationAt(player, r, c)
                  << " |";
    }
}

void DrawGuessBoardLine(const Player &player, int r)
{
    char rowName = r + 'A';
    std::cout << rowName << "|";
    for (int c = 0; c < BOARD_SIZE; c++)
    {
        std::cout << " "
                  << GetGuessRepresentationAt(player, r, c)
                  << " |";
    }
}

void DrawColumnsRow()
{
    std::cout << " ";
    for (int r = 0; r < BOARD_SIZE; r++)
    {
        std::cout << "  " << r + 1 << " ";
    }
    std::cout << " ";
}

char GetShipRepresentationAt(const Player &player, int row, int column)
{
    const ShipPartType currentCell = player.shipBoard[row][column];

    if (currentCell.isHit)
    {
        return '*';
    }
    else if (currentCell.shipType == ST_AIRCRAFT_CARRIER)
    {
        return 'A';
    }
    else if (currentCell.shipType == ST_BATTLESHIP)
    {
        return 'B';
    }
    else if (currentCell.shipType == ST_CRUISER)
    {
        return 'C';
    }
    else if (currentCell.shipType == ST_DESTROYER)
    {
        return 'D';
    }
    else if (currentCell.shipType == ST_SUBMARINE)
    {
        return 'S';
    }
    else
    {
        return ' ';
    }
}

char GetGuessRepresentationAt(const Player &player, int row, int column)
{
    const GuessType currentCell = player.guessBoard[row][column];
    if (currentCell == GT_HIT)
    {
        return '*';
    }
    else if (currentCell == GT_MISSED)
    {
        return 'o';
    }
    else
    {
        return ' ';
    }
}

const char *GetShipNameForShipType(ShipType shipType)
{
    switch (shipType)
    {
    case ST_AIRCRAFT_CARRIER:
        return "Aircraft Carrier";
        break;
    case ST_BATTLESHIP:
        return "Battleship";
        break;
    case ST_CRUISER:
        return "Cruiser";
        break;
    case ST_DESTROYER:
        return "Destroyer";
        break;
    case ST_SUBMARINE:
        return "Submarine";
        break;
    default:
        return "none";
        break;
    }
}
