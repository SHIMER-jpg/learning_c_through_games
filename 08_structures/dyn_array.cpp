// Problem: Improve your Dynamic array that you made previously by using structs to hold the pointer to the dynamic array and the size and capacity of the array:

// struct DynamicArray{
//    int * dynamicArray;
//    int capacity;
//    int size;
// };

// Problem 1: Create a dynamic array of integers that can be resized every time the array is full.
// There should be 5 functions that will be used with this dynamic array:

// 1.
// --> int * CreateDynamicArray(int capacity, int& size);
// This will do the first creation of the dynamic array based on the capacity passed in to the CreateDynamicArray function.

// 2.
// --> void DeleteDynamicArray(int* dynamicArray, int &size);
// DeleteDynamicArray will actually delete the memory created by CreateDynamicArray. Size should be set to 0

// 3.
// --> bool InsertElement(int*dynamicArray, int element, int & size, int capacity);
// InsertElement will add a new element to the end of the array and increase the size by 1.
// It should return false if it doesn't have the capacity to add the new element and true otherwise.

// 4.
// --> void DeleteElement(int* dynamicArray, int elementIndex, int & size);
// DeleteElement will remove the element at elementIndex. There should be no empty spaces between elements. The dynamic array should not be resized.

// 5.
// --> void ResizeDynamicArray(int** dynamicArray, int size, int newCapacity);
// ResizeDynamicArray should resize the array to be newCapacity.
// All the previous elements in the dynamic array should remain intact and in the order they were in beforehand.
// What's a way you could use to change the type of data being held in the dynamic array?

#include <iostream>
#include <cctype>
#include <cstring>
#include <stdlib.h>

using namespace std;

const int IGNORE_CHARS = 25;
const char *INPUT_ERROR = "Input error, please try again!";

struct DynamicArray
{
    int *HEAD;
    int _capacity;
    int _size;

    DynamicArray(int size, int capacity);
    int *CreateDynamicArray(int capacity, int &size);
    void DeleteDynamicArray(int *dynamicArray, int &size);
    bool InsertElement(int *dynamicArray, int element, int &size, int capacity);
    void DeleteElement(int *dynamicArray, int elementIndex, int &size);
    void ResizeDynamicArray(int **dynamicArray, int size, int newCapacity);
    void LogArray();
};

DynamicArray::DynamicArray(int size, int capacity)
{
    this->_size = size;
    this->_capacity = capacity;
}

int *DynamicArray::CreateDynamicArray(int capacity, int &size)
{
    int *NEW_HEAD = new int[capacity];
    return NEW_HEAD;
}

void DynamicArray::LogArray()
{
    int *aux = this->HEAD;
    int capacity = this->_capacity;
    cout << "********************" << endl;
    cout << "PRINT POINTER" << endl;
    for (int i = 0; i < capacity; i++)
    {
        cout << "ITEM: " << *aux << endl;
        aux++;
    }
    cout << "END" << endl;
}

void DeleteDynamicArray(int *dynamicArray, int &size)
{
    delete dynamicArray;
    size = 0;
}

int main()
{
    DynamicArray dynArr = DynamicArray(0, 3);
    dynArr.CreateDynamicArray(dynArr._capacity, dynArr._size);
    dynArr.DeleteDynamicArray(dynArr.HEAD, dynArr._size);
    cout << dynArr._size << endl;
    return 0;
}