/*
Problem 1: Write a function that will reverse a C String. For example if the string was "Hello" it should be reversed to "olleH"

Problem 2: Write a program to read elements in array and copy all elements of first array into second array.

Problem 3: Write a program to insert an element in array at specified position.

Example:
If the elements of array are: 10, 20, 30, 40, 50
After inserting 25 at position 3
Elements of array are: 10, 20, 25, 30, 40, 50

Problem 4: Write a program to delete an element from an array at specified position. The program should also print an error message if the delete position is invalid. There should be no empty elements between the numbers.

Example:
If the array elements are - 10, 20, 30, 40, 50
After deleting element at position 2
Elements of array - 10, 30, 40, 50
*/

#include <iostream>
#include <cctype>

using namespace std;

void reverse(char *string);
int StringLength(char *string);
void copyArray(int v1[], int v2[], int length);
void logArray(int array[], int length);
void insertIntoArray(int array[], int length, int value, int position);
void removeFromArray(int array[], int length, int position);

int main()
{
    cout << "PROBLEM 1" << endl;
    char toReverse[] = "See everyone as god in Drag";
    cout << "Reversing String: " << toReverse << endl;
    reverse(toReverse);
    cout << toReverse << endl;
    cout << "-----------------" << endl;

    cout << "PROBLEM 2" << endl;
    int v1[5] = {1, 2, 3, 4, 5};
    int v2[5] = {0, 0, 0, 0, 0};
    cout << "V1: ";
    logArray(v1, 5);
    cout << "V2: ";
    logArray(v2, 5);
    cout << "Copying array v1 to v2" << endl;
    copyArray(v1, v2, 5);
    cout << "V1: ";
    logArray(v1, 5);
    cout << "V2: ";
    logArray(v2, 5);
    cout << "-----------------" << endl;

    cout << "PROBLEM 3" << endl;
    int v3[10] = {10, 20, 55, 30, 40};
    cout << "V3: ";
    logArray(v3, 10);
    cout << "Inserting value 999 at position 4" << endl;
    insertIntoArray(v3, 10, 999, 4);
    cout << "V3: ";
    logArray(v3, 10);

    cout << "-----------------" << endl;
    cout << "PROBLEM 4" << endl;
    cout << "Removing value 999 at position 4" << endl;
    removeFromArray(v3, 10, 4);
    cout << "V3: ";
    logArray(v3, 10);

    return 0;
}

// PROBLEM 1
void reverse(char *string)
{
    int length = StringLength(string);
    char swap;
    for (int i = length - 1; i >= length / 2; i--)
    {
        swap = string[length - i - 1];
        string[length - i - 1] = string[i];
        string[i] = swap;
    }
    return;
}

int StringLength(char *string)

{
    int length = 0;
    char *p = string;
    if (string != nullptr)
    {
        while (*p != '\0')
        {
            length++;
            p++;
        }
    }
    return length;
}

// PROBLEM 2
void copyArray(int v1[], int v2[], int length)
{
    for (int i = 0; i < length; i++)
    {
        v2[i] = v1[i];
    }
}

void logArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i];
        cout << " ";
    }
    cout << endl;
}

// PROBLEM 3
void insertIntoArray(int array[], int length, int value, int position)
{
    // Shift everything one place from existing position
    for (int i = length; i > position; i--)
    {
        if (i - 1 > position)
        {
            array[i] = array[i - 1];
        }
    }
    // insert value
    array[position - 1] = value;
}

// PROBLEM 4
void removeFromArray(int array[], int length, int position)
{
    // Shift everything one place from existing position
    for (int i = position - 1; i < length; i++)
    {
        if (i + 1 < length)
        {
            array[i] = array[i + 1];
        }
    }
}