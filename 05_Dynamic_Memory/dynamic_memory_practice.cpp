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

// PROBLEM 2: Read a phrase from the user and output it
//  char buffer[256]
//  cin.get(buffer, 256 -1)
// PROBLEM 3: reverse copy the phrase inputed by the function in 1
// #include Cstring
// strlen(phrase)

#include <iostream>
#include <cctype>

using namespace std;

int *CreateDynamicArray(int capacity, int &size);
void DeleteDynamicArray(int *dynamicArray, int &size);
bool InsertElement(int *dynamicArray, int element, int &size, int capacity);
void DeleteElement(int *dynamicArray, int elementIndex, int &size);
void ResizeDynamicArray(int **dynamicArray, int size, int newCapacity);
void LogArray(int *dynamicArray, int capacity);

int main()
{
    // this behaves as the main class
    int capacity = 5;
    int size = 0;
    int *array = CreateDynamicArray(capacity, size);

    LogArray(array, capacity);
    // cout << "Insert 1" << endl;
    InsertElement(array, 1, size, capacity);
    // cout << "Size: " << size << endl;
    // cout << "Insert 1" << endl;
    InsertElement(array, 2, size, capacity);
    // cout << "Size: " << size << endl;
    // cout << "Insert 1" << endl;
    InsertElement(array, 3, size, capacity);
    // cout << "Size: " << size << endl;
    // cout << "Insert 1" << endl;
    InsertElement(array, 4, size, capacity);
    // cout << "Size: " << size << endl;
    // cout << "Insert 1" << endl;
    InsertElement(array, 5, size, capacity);
    // cout << "Size: " << size << endl;
    // cout << "Insert 1" << endl;
    InsertElement(array, 6, size, capacity);
    // cout << "Size: " << size << endl;

    LogArray(array, capacity);

    DeleteDynamicArray(array, size);
    return 0;
}

int *CreateDynamicArray(int capacity, int &size)
{
    int *dynamicArray = new int[capacity];
    cout << "********************" << endl;
    cout << "Created ARRAY: " << dynamicArray << endl;
    cout << "Capacity: " << capacity << endl;
    return dynamicArray;
}

void DeleteDynamicArray(int *dynamicArray, int &size)
{
    cout << "DELETED ARRAY: " << dynamicArray << endl;
    delete[] dynamicArray;
    size = 0;
}

bool InsertElement(int *dynamicArray, int element, int &size, int capacity)
{
    int *head = dynamicArray;

    if (size == capacity)
    {
        cout << "FULL CAPACITY - RESIZING" << endl;
        ResizeDynamicArray(&head, size, capacity + 1);
    }
    head[size] = element;
    size++;

    return true;
}

void DeleteElement(int *dynamicArray, int elementIndex, int &size) {}
void ResizeDynamicArray(int **dynamicArray, int size, int newCapacity)
{
    int *head = *dynamicArray;

    int *newArray = CreateDynamicArray(newCapacity, size);
    cout << "NEW ARRAY" << endl;
    LogArray(newArray, newCapacity);
    cout << "OLD ARRAY" << endl;
    LogArray(*dynamicArray, newCapacity - 1);
    for (int i = 0; i < size; i++)
    {
        cout << i << " " << size << endl;
        cout << newArray[i] << endl;
        cout << head[i] << endl;
        newArray[i] = head[i];
    }
}

void LogArray(int *dynamicArray, int capacity)
{
    int *head = dynamicArray;
    cout << "********************" << endl;
    cout << "PRINT POINTER" << endl;
    for (int i = 0; i < capacity; i++)
    {
        cout << "ITEM: " << *head << endl;
        head++;
    }
    cout << "END" << endl;
}