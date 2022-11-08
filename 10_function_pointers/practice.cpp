/*
Problem 1:
How would you write a 2D array using only a 1D array. What extra functions mi ght
you need to accomplish this?

                Col = 3
              0   1   2
            +---+---+---+
            | 0 | 1 | 2 |
            +---+---+---+
    Row = 3 | 3 | 4 | 5 |
            +---+---+---+
            | 6 | 7 | 8 |
            +---+---+---+
*/

/*
Problem 2:
Write a mini calculator program that takes in a character ('+', '-', *, '/") and 2
integers and outputs the result. Use function pointers for this.
*/

#include <iostream>
#include <cctype>

using namespace std;

void p1();
int Index(int r, int c, int numberOfColumns);

void p2();
int Sum(int i1, int i2);
int Subtraction(int i1, int i2);
int Multiplication(int i1, int i2);
int Division(int i1, int i2);
void Output(int i1, int i2, int (*Function)(int i1, int i2));

int main()
{

    p1();
    p2();
    return 0;
};

void p1()
{
    cout << "INIT P1: " << endl;
    const int MAX = 5;
    const int length = MAX * MAX;
    int array[length];

    cout << "Filling array with numbers" << endl;
    for (int i = 0; i < length; i++)
    {
        array[i] = i + i;
    }

    cout << "Showing all indexes" << endl;

    for (int r = 0; r < MAX; r++)
    {

        for (int c = 0; c < MAX; c++)
        {
            cout << "| " << Index(r, c, MAX) << " |";
        }
        cout << endl;
    }
}

int Index(int r, int c, int numberOfColumns)
{
    return ((r * numberOfColumns) + c);
}

void p2()
{
    char operation = '/';
    cout << "INIT P2: " << endl;
    switch (operation)
    {
    case '+':
        Output(2, 2, Sum);
        break;
    case '-':
        Output(2, 2, Subtraction);
        break;
    case '*':
        Output(2, 2, Multiplication);
    case '/':
        Output(2, 2, Division);
    default:
        break;
    }
}

int Sum(int i1, int i2)
{
    return i1 + i2;
}

int Subtraction(int i1, int i2)
{
    return i1 - i2;
}

int Multiplication(int i1, int i2)
{
    return i1 * i2;
}

int Division(int i1, int i2)
{
    return i1 / i2;
}

void Output(int i1, int i2, int (*Function)(int i1, int i2))
{
    cout << "Result is: " << Function(i1, i2) << endl;
}