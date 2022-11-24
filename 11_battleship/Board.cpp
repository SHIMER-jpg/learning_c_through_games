#include <iostream>
#include ".\Types.h"
#include ".\Utils.h"

const char *INPUT_ERROR_STRING_BOARD = "Please select a valid input";

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
void SetupAiBoard(Player &player);
ShipPositionType GetRandomPosition();

void SetupBoards(Player &player)
{
    ClearBoards(player);

    if (player.playerType == PT_AI)
    {
        SetupAiBoard(player);
        return;
    }

    for (int i = 0; i < NUM_SHIPS; i++)
    {
        DrawBoards(player);
        Ship &currentShip = player.ships[i];
        ShipPositionType position;
        ShipOrientationType orientation;
        do
        {
            std::cout << player.playerName << " set position and orientation for your " << GetShipNameForShipType(currentShip.shipType) << std::endl;
            position = GetBoardPosition();
            orientation = GetShipOrientation();

        } while (!IsValidPlacement(player, currentShip, position, orientation));

        PlaceShipOnBoard(player, currentShip, position, orientation);
    }
}

ShipPositionType GetRandomPosition()
{
    ShipPositionType guess;
    guess.row = rand() % BOARD_SIZE;
    guess.col = rand() % BOARD_SIZE;
    return guess;
}

void SetupAiBoard(Player &player)
{
    ShipPositionType pos;
    ShipOrientationType orientation;
    for (int i = 0; i < NUM_SHIPS; i++)
    {
        Ship &currentShip = player.ships[i];
        do
        {
            pos = GetRandomPosition();
            orientation = ShipOrientationType(rand() % 2);
        } while (!IsValidPlacement(player, currentShip, pos, orientation));

        PlaceShipOnBoard(player, currentShip, pos, orientation);
    }
}

ShipType UpdateBoards(ShipPositionType guess, Player &currentPlayer, Player &otherPlayer)
{
    std::cout << "\033[1;31m[DEBUG]: UPDATING BOARD WITH " << &guess
              << "\033[0m\n"
              << std::endl;

    if (otherPlayer.shipBoard[guess.row][guess.col].shipType != ST_NONE)
    {
        currentPlayer.guessBoard[guess.row][guess.col] = GT_HIT;
        otherPlayer.shipBoard[guess.row][guess.col].isHit = true;
    }
    else
    {
        currentPlayer.guessBoard[guess.row][guess.col] = GT_MISSED;
    }

    return otherPlayer.shipBoard[guess.row][guess.col].shipType;
}

ShipPositionType GetBoardPosition()
{
    char rowInput;
    int colInput;
    const char validRowInputs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    const int validColumnInput[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    rowInput = GetCharacter("Please input a row (A - J): ", INPUT_ERROR_STRING_BOARD, validRowInputs, BOARD_SIZE, CC_UPPER_CASE);
    colInput = GetInteger("Please input a column (1 - 10): ", INPUT_ERROR_STRING_BOARD, validColumnInput, BOARD_SIZE);

    return MapBoardPosition(rowInput, colInput);
}

ShipPositionType MapBoardPosition(char rowInput, int colInput)
{
    int realRow = rowInput - 'A';
    int realCol = colInput - 1;

    ShipPositionType boardPosition;
    boardPosition.row = realRow;
    boardPosition.col = realCol;

    return boardPosition;
}

ShipOrientationType GetShipOrientation()
{
    ShipOrientationType orientation;
    const char validInput[2] = {'H', 'V'};
    char input = GetCharacter("Please choose a orientation H or V: ", INPUT_ERROR_STRING_BOARD, validInput, 2, CC_UPPER_CASE);

    if (input == validInput[0])
    {
        return SO_HORIZONTAL;
    }
    else
    {
        return SO_VERTICAL;
    }
}

bool IsValidPlacement(const Player &player, const Ship &currentShip, const ShipPositionType &position, const ShipOrientationType &orientation)
{
    if (orientation == SO_HORIZONTAL)
    {
        for (int c = position.col; c < (position.col + currentShip.shipSize); c++)
        {
            if (player.shipBoard[position.row][c].shipType != ST_NONE || c >= BOARD_SIZE)
            {
                std::cout << "Invalid placement please try again " << std::endl;
                return false;
            }
        }
    }
    else
    {
        for (int r = position.col; r < (position.col + currentShip.shipSize); r++)
        {
            if (player.shipBoard[r][position.col].shipType != ST_NONE || r >= BOARD_SIZE)
            {
                std::cout << "Invalid placement please try again " << std::endl;
                return false;
            }
        }
    }
    return true;
}

void PlaceShipOnBoard(Player &player, Ship &currentShip, ShipPositionType &position, ShipOrientationType &orientation)
{
    currentShip.position = position;
    currentShip.orientation = orientation;

    if (orientation == SO_HORIZONTAL)
    {
        for (int c = position.col; c < (position.col + currentShip.shipSize); c++)
        {
            player.shipBoard[position.row][c].shipType = currentShip.shipType;
            player.shipBoard[position.row][c].isHit = false;
        }
    }
    else
    {
        for (int r = position.col; r < (position.col + currentShip.shipSize); r++)
        {
            player.shipBoard[r][position.col].shipType = currentShip.shipType;
            player.shipBoard[r][position.col].isHit = false;
        }
    }
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
    ClearScreen();
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
