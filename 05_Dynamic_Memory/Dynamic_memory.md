## Basics

- Declare a new pointer variable
`int * newIntPtr = new int`;

- Assign something to the pointer
`*newIntPtr = 8`

- Free the memory used by the pointer
`delete newIntPtr`


## Dynamic Arrays
- Declare a new array
`int * newIntArray = new int[10]`;

- This can be created with any dynamic parameter such as
`int * newIntArray = new int[some]`;

- Free the memory used by the array
`delete[] newIntArray`

Avoid assigning outside the array bounds 
Avoid moving the initial pointer, instead use a copy.

### Best practices

- Who creates it deletes it

- Don't delete more than once the same pointer, you can set it to nullptr

- Don't change where the pointing are pointing, instead use a copy

- Always have something pointing to the HEAD

- Don't assign OUTSIDE the index range
