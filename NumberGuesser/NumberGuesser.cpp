#include <iostream>
using namespace std;

bool NumberGuesser(int difficulty);
int GetInput();
int GetGuess(int lowRange, int highRange);
int GetRandomNumber(int open, int close);

int main()
{
    // Create a program called number guesser.
    // There will be a secret number that is set at the start of the program without any user input.
    // The secret number should be picked from a certain range.
    // The range of the number should be output to the player.
    // The player should be prompted to enter his guess.
    // The prompt should show how many guesses the player has left.
    // The player will then enter his guess.
    // If the guess is too high then the game will output that the guess was too high.
    // If the guess was too low then the game will output that it was too low.
    // The player only has a certain number of guesses.
    // The number of guesses should be based on the range of the secret number.
    // Any wrong guess will decrement the number of guesses left.
    // The game ends by saying what the secret number was regardless of if the player guessed the right number.
    // When the game is over, the player should be prompted if he would like to play again.
    // If yes then the secret number should change.
    // Any input errors by the player should have proper handling.

    bool play = true;
    int difficulty;
    cout << "**** WELCOME TO NUMBER GUESSER ****" << endl;
    do
    {
        cout << "Select difficulty" << endl;
        cout << "1 -- Range 1 to 100 -- 5 Tries" << endl;
        cout << "2 -- Range 100 to 500 -- 4 Tries" << endl;
        cout << "3 -- Range 500 to 1500 -- 3 Tries" << endl;
        difficulty = GetInput() - 1;
        if (play && difficulty >= 0 && difficulty < 3)
        {
            play = NumberGuesser(difficulty);
        }
        else
        {
            cout << "Ups, that option does not seem to be valid: " << difficulty + 1 << endl;
        }
    } while (play);

    return 0;
}

bool NumberGuesser(int difficulty)
{
    const int DIFFICULTY_MATRIX[3][3] = {{1, 100, 5}, {100, 500, 4}, {500, 1500, 3}};
    int guessesLeft = DIFFICULTY_MATRIX[difficulty][2];
    int lowRange = DIFFICULTY_MATRIX[difficulty][0];
    int highRange = DIFFICULTY_MATRIX[difficulty][1];
    int randomNumber = GetRandomNumber(DIFFICULTY_MATRIX[difficulty][0], DIFFICULTY_MATRIX[difficulty][1]);
    int guess;
    int playAgain;

    cout << "*** PARAMETERS ***" << endl;
    cout << randomNumber << endl;
    cout << "***********" << endl;

    while (guessesLeft > 0)
    {
        cout << "You have " << guessesLeft << " guesses left"
             << endl;
        cout << "Guess a Number between " << DIFFICULTY_MATRIX[difficulty][0] << " and " << DIFFICULTY_MATRIX[difficulty][1] << " " << endl;
        guess = GetGuess(lowRange, highRange);
        if (guess == randomNumber)
        {
            cout << "You Guessed!" << endl;
            break;
        }
        else if (guess > randomNumber)
        {
            cout << "\nYour guess was to high"
                 << endl;
        }
        else
        {
            cout << "\nYour guess was to low"
                 << endl;
        }
        guessesLeft--;
    }
    cout << "The secret number was: " << randomNumber << endl;
    cout << "If you want to play again, enter 0" << endl;
    playAgain = GetInput();
    return playAgain == 0;
}

int GetRandomNumber(int open, int close)
{
    int result = open + (rand() % (open - close));
    return result;
}

int GetGuess(int lowRange, int highRange)
{
    int guess;
    bool validGuess = false;
    do
    {
        guess = GetInput();
        if (guess > highRange)
        {
            cout << "Max number is: " << highRange << endl;
        }
        else if (guess < lowRange)
        {
            cout << "Min number is: " << lowRange << endl;
        }
        else
        {
            validGuess = true;
        }

    } while (!validGuess);
    return guess;
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
