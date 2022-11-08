#include <iostream>
using namespace std;

int main()
{
    const int MAX = 5;
    int array2D[MAX][MAX]; // contiguos in memory

    int(*pointer)[MAX] = array2D;
    // also works with an array of pointers;
    //
    // int ** pointer = new int *[MAX] // flexible in row and column sizes, discontinuiedd in memory
    //
    // for(int r = 0; r< MAX; r++){
    //    pointer[r] = new int[MAX]
    //           or
    //    delete [] pointer[r];
    // }

    // also we delete rows first ()

    for (int r = 0; r < MAX; r++)
    {

        for (int c = 0; c < MAX; c++)
        {
            pointer[r][c] = r * c;
            cout << " " << pointer[r][c] << " ";
        }
        cout << endl;
    }

    return 0;
}