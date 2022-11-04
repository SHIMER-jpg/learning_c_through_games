#include <iostream>
#include <cctype>
#include <cstring>
#include <stdlib.h>
#include "Utils.h"

using namespace std;

const int IGNORE_CHARS = 25;
const char *INPUT_ERROR = "Input error, please try again!";

int GetSecretPhrase(char secretPhrase[], int MAX_LENGTH_OF_PHRASE);
char *MakeHiddenPhrase(const char *secretPhrase, int secretPhraseLength);
void DrawBoard(int numberOfGuessesLeft, const char *noptrHiddenPhrase);
bool WantToPlayAgain();
bool IsGameOver(int numberOfGuessesLeft, const char *noptrHiddenPhrase, const char secretPhrase[]);
void UpdateBoard(char guess, char *noptrHiddenPhrase, const char secretPhrase[], int secretPhraseLength, int &numberOfGuessesLeft);
void DisplayResult(const char *secretPhrase, int numberOfGuessesLeft);

int main()
{
    do
    {
        // Initialize game
        const int MAX_LENGTH_OF_PHRASE = 256;
        char secretPhrase[MAX_LENGTH_OF_PHRASE];
        char *optrHiddenPhrase = nullptr;
        int numberOfGuessesLeft = 7;

        // Input secret phrase
        int secretPhraseLength = GetSecretPhrase(secretPhrase, MAX_LENGTH_OF_PHRASE);
        optrHiddenPhrase = MakeHiddenPhrase(secretPhrase, secretPhraseLength);
        char guess;
        DrawBoard(numberOfGuessesLeft, optrHiddenPhrase);
        do
        {
            // Get Guess
            guess = GetCharacter("Pick a letter! ", INPUT_ERROR);
            // UpdateBoard
            UpdateBoard(guess, optrHiddenPhrase, secretPhrase, secretPhraseLength, numberOfGuessesLeft);

            DrawBoard(numberOfGuessesLeft, optrHiddenPhrase);
        } while (IsGameOver(numberOfGuessesLeft, optrHiddenPhrase, secretPhrase));

        // Display results
        DisplayResult(secretPhrase, numberOfGuessesLeft);

        delete[] optrHiddenPhrase;
    } while (WantToPlayAgain());

    return 0;
}

bool IsGameOver(int numberOfGuessesLeft, const char *noptrHiddenPhrase, const char secretPhrase[])
{
    bool hasDash = false;
    for (int i = 0; i < strlen(secretPhrase); i++)
    {
        if (noptrHiddenPhrase[i] == '-')
        {
            hasDash = true;
            break;
        }
    }
    cout << hasDash << endl;
    return numberOfGuessesLeft > 0 && hasDash;
}

void UpdateBoard(char guess, char *noptrHiddenPhrase, const char secretPhrase[], int secretPhraseLength, int &numberOfGuessesLeft)
{
    bool found = false;
    for (int i = 0; i < secretPhraseLength; i++)
    {
        if (tolower(secretPhrase[i]) == tolower(guess))
        {
            noptrHiddenPhrase[i] = secretPhrase[i];
            found = true;
        }
    }

    if (!found)
        numberOfGuessesLeft--;
}

void DisplayResult(const char *secretPhrase, int numberOfGuessesLeft)
{
    const char *result = numberOfGuessesLeft > 0 ? "You won!" : "You lost!";
    cout << "The answer was: " << secretPhrase << endl;
    cout << result << endl;
}

int GetSecretPhrase(char secretPhrase[], int MAX_LENGTH_OF_PHRASE)
{
    bool failure = false;
    do
    {
        cout << "Please enter a secret phrase: ";
        cin.get(secretPhrase, MAX_LENGTH_OF_PHRASE);
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(IGNORE_CHARS, '\n');
            cout << INPUT_ERROR << endl;
            failure = true;
        }
        else
        {
            int length = strlen(secretPhrase);
            if (length == 0)
            {
                cout << "Enter a longer phrase" << endl;
                failure = true;
            }
        }
    } while (failure);
    return strlen(secretPhrase);
}

char *MakeHiddenPhrase(const char *secretPhrase, int secretPhraseLength)
{
    char *hiddenPhrase = new char[secretPhraseLength + 1];

    for (int i = 0; i < secretPhraseLength; i++)
    {
        if (secretPhrase[i] != ' ')
            hiddenPhrase[i] = '-';
        else
            hiddenPhrase[i] = ' ';
    }
    hiddenPhrase[secretPhraseLength + 1] = '\0';
    return hiddenPhrase;
}

void DrawBoard(int numberOfGuessesLeft, const char *noptrHiddenPhrase)
{
    system("CLS");
    switch (numberOfGuessesLeft)
    {
    case 0:
    {
        cout << "+---+" << endl;
        cout << "|   |" << endl;
        cout << "|   0" << endl;
        cout << "|  /|\\" << endl;
        cout << "|  / \\" << endl;
        cout << "-+-" << endl
             << endl;
    }
    break;
    case 1:
    {
        cout << "+---+" << endl;
        cout << "|   |" << endl;
        cout << "|   0" << endl;
        cout << "|  /|\\" << endl;
        cout << "|  /  " << endl;
        cout << "-+-" << endl
             << endl;
    }
    break;
    case 3:
    {
        cout << "+---+" << endl;
        cout << "|   |" << endl;
        cout << "|   0" << endl;
        cout << "|  /|\\" << endl;
        cout << "|    " << endl;
        cout << "-+-" << endl
             << endl;
    }
    break;
    case 4:
    {
        cout << "+---+" << endl;
        cout << "|   |" << endl;
        cout << "|   0" << endl;
        cout << "|  /|" << endl;
        cout << "|   " << endl;
        cout << "-+-" << endl
             << endl;
    }
    break;
    case 5:
    {
        cout << "+---+" << endl;
        cout << "|   |" << endl;
        cout << "|   0" << endl;
        cout << "|   |" << endl;
        cout << "|    " << endl;
        cout << "-+-" << endl
             << endl;
    }
    break;
    case 6:
    {
        cout << "+---+" << endl;
        cout << "|   |" << endl;
        cout << "|   0" << endl;
        cout << "|    " << endl;
        cout << "|    " << endl;
        cout << "-+-" << endl
             << endl;
    }
    break;
    case 7:
    {
        cout << "+---+" << endl;
        cout << "|   |" << endl;
        cout << "|    " << endl;
        cout << "|    " << endl;
        cout << "|    " << endl;
        cout << "-+-" << endl
             << endl;
    }
    break;
    default:
        break;
    }

    cout << "Secret Phrase: " << noptrHiddenPhrase << endl;
};

bool WantToPlayAgain()
{
    const char validInputs[] = {'y', 'n'};
    char response = GetCharacter("Would you like to play again? (y/n) ", INPUT_ERROR, validInputs, 2, CC_EITHER);
    return response == validInputs[0];
}