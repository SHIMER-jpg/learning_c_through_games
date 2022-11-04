#include <iostream>
#include <cctype>
#include <cstring>
#include <stdlib.h>
#include ".\Utils.h"

using namespace std;
char GetCharacter(const char *prompt, const char *error);
char GetCharacter(const char *prompt, const char *error, const char validInput[], int validInputLength, CharCaseType charCase);


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

char GetCharacter(const char *prompt, const char *error, const char validInput[], int validInputLength, CharCaseType charCase)
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
                if(charCase == CC_LOWER_CASE)
                    input = tolower(input);
                if(charCase == CC_UPPER_CASE)
                    input = toupper(input);
                    
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
