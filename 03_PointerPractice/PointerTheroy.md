### CHEATSHEET

- Pointers Store addresses of variables:

`int * pointerName;` -> Declares a int pointer type variable

`*pointerName` -> Access the variable stored in the pointer, known as _*de-referencing*_

`int * pointerName = nullptr;` -> Points to literally nothing, and cannot be de-referenced

`&variable;`  -> Returns a hex address, known as _*reference*_

`int x = 5;`
`int * pointerName = &x;` -> Stores the address of the integer above, wouldn't work with other type

`int & intRef = x;` -> Creates a reference _"intRef"_ to _"x"_, which if altered, ends up altering _x_

`int & intRef2;` -> Throws an error, as references need to be defined, since they act like a constant

`intRef = 10;` -> would change the value of _x_ to _10_

### *HERE IS WHERE IT GET'S MESSY*

`const int * xPtr = &x;` -> Stores the address of _x_ without being able to de-reference it later, yet being able to change where it points
- `*xPtr = 10;` -> this cant be done
- `xPtr = &y;` -> this can be done

`int * const yPtr = &y;` -> Can't change where it points but it can be de-referenced, this are basically references
- `*yPtr = 19;` -> Works
- `yPtr = &x;` -> Won't work

`const int & xRef = x;` -> Returns a reference that cannot be changed
`const int * const xPtr2 = &x;` -> Basically the same that above, but more complex.

If pointers point to an array like:

`int array[5] = {1,2,3,4,5}
int * ptr = &array[0] or just 'array'`

then ptr++; moves the pointer 1 block of the type of the array
