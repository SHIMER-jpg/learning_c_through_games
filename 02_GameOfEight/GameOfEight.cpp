/*
The Game of Eight

------------------

The game of 8 is played by 2 players

The game starts with the initial number 8 (from here on refered to as the initial number)
The first player will choose a number from 1 to 3 (from here on refered to as the chosen number)
If the player inputs something outside of the 1 to 3 range it should be an error and the player must choose again
The initial number is subtracted by the chosen number
Then the next player's turn happens
The next player cannot choose the number that the last player chose
If the initial number goes to 0 on your turn, then you win
Otherwise if the number goes below 0, your opponent wins
The player should always see what choices are available to him when prompted to enter his choice
After the game is over, the user should be prompted whether they want to play again


Write a program to solve this problem


SOLUTION:

    1. Set the initial value 8
    2. Get input from player, hiding inputs if needed
        2a. If input is valid, subtract from intial value
        2b. If input is invalid, go back to 2
    3. Validate if game ended
        3a. If so Check if user wants to play again
        3b. If not go to 2
*/

#include <iostream>
#include <cctype>

using namespace std;

bool IsGameOver(int remainingNumber);
bool PlayAgain();
bool ValidateSelection(int selection, int lastInput);
char GetCharInput();
int ChooseNumber(int lastChosen, string playerTurn);
int GetInput();
int GetSelection();
void DisplayResult(int remainingNumber, string playerTurn);
void Play();

int main()
{
    do
    {
        Play();
    } while (PlayAgain());

    return 0;
}

void Play()
{
    int chosenNumber, lastChosen = -1, initialNumber = 8;
    bool isPlayerOneTurn = true;
    string playerTurn;

    do
    {
        playerTurn = isPlayerOneTurn ? "Player one " : "Player two ";

        chosenNumber = ChooseNumber(lastChosen, playerTurn);
        lastChosen = chosenNumber;
        initialNumber = initialNumber - chosenNumber;
        isPlayerOneTurn = !isPlayerOneTurn;
    } while (!IsGameOver(initialNumber));

    DisplayResult(initialNumber, playerTurn);
}
bool PlayAgain()
{
    char answer;
    do
    {
        cout << "Would you like to play again (y/n)" << endl;
        answer = tolower(GetCharInput());

    } while (answer != 'y' && answer != 'n');

    return answer == 'y';
}

bool IsGameOver(int remainingNumber)
{
    return remainingNumber <= 0;
}

void DisplayResult(int remainingNumber, string playerTurn)
{
    if (remainingNumber == 0)
    {
        cout << playerTurn << "Won!" << endl;
    }
    else
    {
        cout << playerTurn << "Lost!" << endl;
    }
}

int ChooseNumber(int lastChosen, string playerTurn)
{

    int selection;
    bool failure = false;
    do
    {
        cout << playerTurn << "select a number: " << endl;
        for (int x = 1; x <= 3; x++)
        {
            if (x != lastChosen)
            {
                cout << "* " << x << endl;
            }
        }
        selection = GetInput();
        failure = !ValidateSelection(selection, lastChosen);
        if (failure)
        {
            cout << "Input a valid number" << endl;
        }
    } while (failure);
    return selection;
}

int GetInput()
{
    bool failure = false;
    int input, IGNORE = 256;

    do
    {
        cin >> input;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(IGNORE, '\n');
            cout << "Input error" << endl;
            cout << "Please input a number: " << endl;
            failure = true;
        }
    } while (failure);

    return input;
}

bool ValidateSelection(int selection, int lastInput)
{
    return (selection == 1 || selection == 2 || selection == 3) && (selection != lastInput);
}

char GetCharInput()
{
    bool failure = false;
    char input;
    int IGNORE = 256;

    do
    {
        cin >> input;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(IGNORE, '\n');
            cout << "Input error" << endl;
            cout << "Please input (y/n): " << endl;
            failure = true;
        }
    } while (failure);

    return input;
}