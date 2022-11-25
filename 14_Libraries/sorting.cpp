#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

bool DescCompare(int val1, int val2);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    const int MAX = 10;
    const int RND_MAX = 100;

    vector<int> intVec;
    intVec.reserve(MAX);
    cout << "Random list: " << endl;

    for (int i = 0; i < MAX; i++)
    {
        int x = rand() % RND_MAX;
        intVec.push_back(x);

        cout << x << endl;
    }

    sort(intVec.begin(), intVec.end(), DescCompare);

    cout << "Sorted list: " << endl;
    for (int i = 0; i < MAX; i++)
    {

        cout << intVec[i] << endl;
    }

    return 0;
}

bool DescCompare(int val1, int val2)
{
    return val1 > val2;
}
