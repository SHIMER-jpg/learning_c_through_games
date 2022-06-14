#include <iostream>

using namespace std;

void Swap(int &x, int &y);

/*
CHEATSHEET:

 Pointers Store addresses of variables:

 int * pointerName; => Declares a int pointer type variable

 *pointerName => Access the variable stored in the pointer, known as de-referencing

 int * pointerName = nullptr; => Points to literally nothing, and cannot be de-referenced

 &variable;  => Returns a hex address, known as reference

 int x = 5;
 int * pointerName = &x; ==> Stores the address of the integer above, wouldn't work with other type

 int & intRef = x; => Creates a reference "intRef" to "x", which if altered, ends up altering x

 int & intRef2; => Throws an error, as references need to be defined, since they act like a constant

 intRef = 10; => would change the value of x to 10

******************HERE IS WHERE IT GET'S MESSY****************

 const int * xPtr = &x; => Stores the address of x without being able to de-reference it later, yet being able to change where it points
 *xPtr = 10; => this cant be done
 xPtr = &y; => this can be done

 int * const yPtr = &y; => Can't change where it points but it can be de-referenced, this are basically references
 *yPtr = 19; => Works
 yPtr = &x; => Won't work

 const int & xRef = x; => Returns a reference that cannot be changed
 const int * const xPtr2 = &x; => Basically the same that above, but more complex.


*/
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
