#include <iostream>
#include <string>
using namespace std;

void Func(string &aString); // copies aString instead of referencing

int main()
{
    string myString = "Hello";
    string myString2;

    cout << myString << endl;

    cout << "Please enter a string: ";
    cin >> myString2;
    cout << myString2 << endl;

    string myString3 = myString + myString2;
    myString3 += "!";

    cout << myString3 << endl;

    myString[0] = 'h';

    cout << "Final length " << myString3.length() << endl;
    cout << "c_string representation returns a cons char* " << myString3.c_str() << endl;

    return 0;
}
