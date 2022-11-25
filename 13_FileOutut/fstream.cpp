#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream outFile;
    outFile.open("test.txt");
    outFile << "Hello world first file" << endl;
    outFile.close();

    ifstream inFile;
    inFile.open("test.txt");
    if (inFile.is_open())
    {
        inFile.seekg(0, inFile.end); // moves cursor to end of file
        int length = inFile.tellg(); // gives position
        inFile.seekg(0, inFile.beg); // moves cursor to start of file

        char *optrBuffer = new char[length + 1];
        inFile.get(optrBuffer, length);

        cout << optrBuffer << " " << length << endl;

        delete[] optrBuffer;
        inFile.close();
    }

    return 0;
}