#include <iostream>
#include <cstring>
using namespace std;

struct BookType
{
    int bookId;
    char title[256];
    char author[256];
    int year;
    float price;
};

void Func(BookType &book); // passing by reference to not duplicate data

//renaming types: typedef existingType newType, usable for readability and changing types in just one place this does not subscribe the existing
typedef int IDType;

//Types
enum DirectionType{
    NORTH=0,
    EAST = 1,
    SOUTH = 2,
    WEST = 4
};

int main()
{
    BookType aBook;

    aBook.bookId = 1;
    strcpy(aBook.title, "A tale");
    strcpy(aBook.author, "Me");
    aBook.year = 1859;
    aBook.price = 23.41;

    cout << "Size of book type: " << sizeof(BookType) << " B" << endl;

    BookType books[10];
    books[0].bookId = 1001;

    // Functions
    Func(aBook);

    // Pointer to a custom structure
    BookType *bookPtr = &aBook;

    // Null ptr custom struc
    BookType *optrBook = new BookType;

    // Accesing struct through pointer (also => (*bookPtr).year )
    cout << "Book year " << bookPtr->year << endl;

    return 0;


    IDType myID=1000;
}

void Func(BookType &book)
{ // use const in definition ot not change reference
    cout << "Book address " << &book << endl;
    cout << "Title in function " << book.title << endl;
}