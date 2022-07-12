#include <iostream>

using namespace std;

void Swap(int &x, int &y);
int main()
{
    int x = 5;
    int y = 15;

    cout << "The value of pre-swap x is: " << x << endl;
    cout << "The value of pre-swap y is: " << y << endl;

    Swap(x, y);

    cout << "The value of x is: " << x << endl;
    cout << "The value of y is: " << y << endl;

    return 0;
}

void Swap(int &x, int &y)
{
    cout << "Received " << &x << " " << &y << endl;
    int swapper = x;
    x = y;
    y = swapper;
}
