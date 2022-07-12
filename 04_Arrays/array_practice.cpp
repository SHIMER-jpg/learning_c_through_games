
#include <iostream>
#include <cctype>

using namespace std;

double DotProduct(const double v1[3], const double v2[3], int length);
char GetCharacter(const char *prompt, const char *error);

char GetCharacter(const char *prompt, const char *error, const char validInput[], int validInputLength);

int main()
{
    double v1[3] = {1, 4, 7};
    double v2[3] = {2, 5, 8};

    char validInput[2] = {'y', 'n'};

    cout << "Dot product of two arrays: " << DotProduct(v1, v2, 3) << endl;
    char input = GetCharacter("Please enter a characteR: ", "Input Error! Please try again.");
    char input2 = GetCharacter("Do you want to play again? (y/n): ", "Input Error! Please try again.", validInput, 2);

    return 0;
}

double DotProduct(const double v1[3], const double v2[3], int length)
{
    double sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += v1[i] * v2[i];
    }
    return sum;
}

char GetCharacter(const char *prompt, const char *error)
{
    char input;
    bool failure;
    do
    {
        failure = false;
        cout << prompt;
        cin >> input;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << error;
            failure = true;
        }
        else
        {
            cin.ignore(256, '\n');
            if (isalpha(input))
            {
                input = tolower(input);
            }
            else
            {
                cout << error << endl;
                failure = true;
            }
        }
    } while (failure);
    return input;
}

char GetCharacter(const char *prompt, const char *error, const char validInput[], int validInputLength)
{
    char input;
    bool failure;
    do
    {
        failure = false;
        cout << prompt;
        cin >> input;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(256, '\n');
            cout << error;
            failure = true;
        }
        else
        {
            cin.ignore(256, '\n');
            if (isalpha(input))
            {
                input = tolower(input);
                for (int i = 0; i < validInputLength; i++)
                {
                    if (validInput[i] == input)
                    {
                        return input;
                    }
                }
            }
            cout << error << endl;
            failure = true;
        }
    } while (failure);
    return input;
}