#include <iostream>
#include <vector>

using namespace std;

void Func(const vector<int> &vecRef);

int main()
{
    vector<int> intVec;
    intVec.reserve(5); // we can reserve a minimum of capacity
    // capacity is doubled when you go overit

    for (int i = 0; i < 20; i++)
    {
        intVec.push_back(5);                              // adds 5 to the end, similar to arrays
        cout << "Size " << intVec.size() << endl;         //
        cout << "Capacity " << intVec.capacity() << endl; // How many elements are allocated in memory
    }

    intVec.pop_back(); // removes last element of vector
    cout << "Size " << intVec.size() << endl;

    intVec.clear();
    if (intVec.empty())
    {
        cout << "The vector is empty" << endl;
    }

    intVec[0] = 5;
    cout << intVec[0] << endl;
}