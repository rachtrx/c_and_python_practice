#include <stdio.h>
#include <stdint.h>
# include <stdlib.h> // IMPT for free()

//  Code statements like printf must be inside a function.

int main() {
    int digit = 42;

    // Type Safety: When using functions like printf, the %p format specifier expects a void* argument.
    printf("1.1 The address of the digit = %p.\n", (void*)&digit);
    // The address of the digit = 0x7ffef94abaa4.

    int *addressOfDigit = &digit;

    printf("1.2 The address of digi = %p.\n", addressOfDigit);
    printf("1.3 The value of digit = %d.\n", *addressOfDigit);

    int num = 5;
    int *p = &num;
    printf("1.4 Address using %%p = %p\n", p);

    char *alphabetAddress; // wild pointer
    char alphabet = 'a';
    alphabetAddress = &alphabet;

    char *alphabetAddress2 = NULL; // null pointer

    void *pointerVariableName = NULL; // void or generic pointers

    void *pointer = NULL;
    int number = 54;
    char alphabet2 = 'z'; // IMPT must be single quotes
    pointer = &number;

    printf("1.5 The value of number = %d\n", *(int *)pointer); // IMPT need to cast because it is void

    pointer = &alphabet2;
    printf("1.6 The value of alphabet = %c\n", *(char *)pointer);

    // IMPT malloc() and calloc() return void pointers. qsort(), an inbuilt sorting function in C, has a function as its argument which takes void pointers as its argument

    int *ptr;
    ptr = (int *)malloc(sizeof(int)); // IMPT
    *ptr = 1;
    printf("1.7 %d\n", *ptr);
    free(ptr); // IMPT dangling ptr
    *ptr = 5;
    printf("1.8 This dangling pointer may print 5. Print: %d\n", *ptr); // may or may not print 5

    // SECTION pointer arithmetic
    printf("\nSection: Pointer Arithmetic\n");

    int ManU = 1;
    int *addressOfManU = &ManU;
    int *anotherAddressOfManU = NULL;
    anotherAddressOfManU = addressOfManU; // valid
    // double *wrongAddressOfManU = addressOfManU // invalid

    int myArray[] = {3, 6, 9, 12, 15};
    int *pointerToMyArray = &myArray[0];
    pointerToMyArray += 1; // valid
    // pointerToMyArray *= 3; // invalid IMPT can only + or -

    int number2 = 5;
    int *ptr2 = &number2;
    // IMPT can use the <stdint.h> for intptr_t, but it works differently... int is 4 bytes on 32bit and 8 bytes on 64bit, so use unsigned long
    unsigned long newAddress = (unsigned long)(ptr2) + 3; 
    unsigned long newAddress2 = (unsigned long)(ptr2) + 3 * sizeof(int);
    printf("2.1 TAKE NOTE %ld is the same address as %ld\n", newAddress, newAddress2);  // Cast back to void* for printing

    int myArray2[] = {3, 6, 9, 12, 15};
    int sixthMultiple = 18;
    int *pointer1 = &myArray2[0];
    int *pointer2 = &myArray2[1];
    int *pointer6 = &sixthMultiple;
    printf("2.2 p2 - p1 = %p - %p = %li\n", pointer2, pointer1, pointer2 - pointer1);

    //  subtracting pointers that do not point to elements of the same array is undefined behavior according to the language standard.
    printf("2.3 RISKY: p6 - p1 = %p - %p = %li\n", pointer6, pointer1, pointer6 - pointer1);

    // SECTION ARRAYS
    // IMPT 1D ARRAYS
    printf("\nSection: Arrays\n");

    int prime[5] = {2, 3, 5, 7, 11};
    printf("3.1 Result using &prime = %p\n", (void *)&prime);
    printf("3.2 Result using prime = %p\n", prime);
    printf("3.3 Result using &prime[0] = %p\n", (void *)&prime[0]);
    printf("When adding 1,\n");
    printf("3.4 Result using &prime = %p - points to entire array\n", &prime + 1);
    printf("3.5 Result using prime = %p - points to 1st element\n", prime + 1);
    printf("3.6 Result using &prime[0] = %p - points to 1st element\n", &prime[0] + 1);

    // Looping over addresses
    printf("\nLoops\n");
    int prime2[5] = {2, 3, 5};
    for(int i = 0; i < 3; i++) {
        // IMPT Using pointers is always faster than subscripts!
        printf("3.7.%i Using subscripts: Index = %i, address &prime2[%i] = %p, value prime2[%i] = %i\n", i + 1, i, i, (void *)&prime2[i], i, prime2[i]);
        printf("3.7.%i Using pointers: Index = %i, address prime2 + %i = %p, value *(prime2 + %i) = %i\n", i + 1, i, i, prime2 + i, i, *(prime2 + i));
    };

    // IMPT 2D ARRAYS
    printf("\n2D Arrays: marks = [5][3]\n");
    int marks[5][3] = {
        {98, 76, 89},
        {81, 96, 79},
        {88, 86, 89}
    };
    printf("\nWhole Array\n");
    printf("3.8.1 Address of whole 2D array (&marks) = %p\n", (void *)&marks);
    printf("3.8.2 Addition of 1 (&marks + 1) results in %p - points after the whole 2D array\n", (void *)&marks + 1);

    printf("\nOuter Array\n");
    printf("3.9.1 Address of marks[0] (marks) = %p\n", marks);
    printf("3.9.2 Addition of 1 (marks + 1) results in %p - marks[1]\n", marks + 1);
    printf("3.10.1 Address of marks[0] (&marks[0]) = %p\n", (void *)&marks[0]);
    printf("3.10.2 Addition of 1 (&marks[0] + 1) results in %p - marks[1]\n", (void *)&marks[0] + 1);

    printf("\nInner Array - also applies to &marks[0][0] and &marks[0][0] + 1\n");
    printf("3.11.1 Address of marks[0][0] (marks[0]) = %p\n", marks[0]);
    printf("3.11.2 Addition of 1 (marks[0] + 1) results in %p - marks[0][1]\n", marks[0] + 1);
    printf("3.11.3 IMPORTANT: marks[i][j] == *(marks[i] + j), marks[i] == *(marks + i), marks[i][j] = *(*(marks + i) + j)\n");

    // SECTION Strings
    // IMPT single string
    printf("\nStrings are 1D array of chars: champions[] = \"Liverpool\"\n");
    char champions[] = "Liverpool";

    printf("\nWhole String\n");
    printf("4.1.1 Pointer to whole string champions (&champions) = %p\n", (void *)&champions);
    printf("4.1.2 Addition of 1 (&champions + 1) results in %p - points to after whole string\n", &champions + 1);   

    printf("\nIndexing strings\n");
    printf("4.2.1 Pointer to champions[0] (&champions[0]) = %p\n", (void *)&champions[0]);
    printf("4.2.2 Addition of 1 (&champions[0] + 1) results in %p - champions[1]\n", (void *)&champions[0] + 1);
    printf("4.3.1 Pointer to champions[0] (champions) = %p\n", champions);
    printf("4.3.2 Addition of 1 (champions + 1) results in %p - champions[1]\n", champions + 1);

    printf("\nGetting value\n");
    printf("4.4.1 Value at 4th character (champions[4]) = %c\n", champions[4]);
    printf("4.4.2 Value at 4th character using pointers *(champions + 4) = %c\n", *(champions + 4));

    // IMPT Array of strings
    printf("\n2D array of characters is an array of strings - char top[6][15]\n");
    char top[6][15] = {
        "Liverpool",
        "Man City",
        "Man United",
        "Chelsea",
        "Leicester",
        "Tottenham",
    };

    printf("\nWhole 2D array\n");
    printf("4.5.1 Pointer to 2D array (&top) = %p\n", (void *)&top);
    printf("4.5.2 Addition of 1 (&top + 1) results in %p\n", (void *)&top + 1);

    printf("\nOuter array\n");
    printf("4.6.1 Pointer to top[0] (&top[0]) = %p\n", (void *)&top[0]);
    printf("4.6.2 Addition of 1 (&top[0] + 1) results in %p - top[1]\n", (void *)&top[0] + 1);
    printf("4.7.1 Pointer to top[0] (top) = %p\n", top);
    printf("4.7.2 Addition of 1 (top + 1) results in %p - top[1]\n", top + 1);

    printf("\nInner array\n");
    printf("4.8.1 Pointer to top[4][0] (top[4]) = %p\n", top[4]);
    printf("4.8.2 Addition of 1 (top[4] + 1) results in %p - top[4][1]\n", top[4] + 1);

    printf("\nGetting value of character\n");
    printf("4.9.1 Value of top[3][1] = %c\n", top[3][1]);
    printf("4.9.2 Value of top[3][1] using pointers = %c\n", *(*(top + 3) + 1));


    // SECTION Array of Pointers
    printf("\nArray of pointers eg. \"int *example1[5];\" and \"char *example2[8], where each pointer points to an array. This allows the array to be assigned as a pointer since the name of an array is itself a pointer. Note - Not an array of arrays!\"\n");

    char *top2[] = {
        "Liverpool",
        "Man City",
        "Man United",
        "Chelsea",
        "Leicester",
        "Tottenham",
    };
    printf("IMPORTANT: Manipulation of strings become much easier using an array of pointers\n");
    char *temporary;
    temporary = top2[3];
    top2[3] = top2[4];
    top2[4] = temporary; // switches Leicester and Chelsea
    printf("\nPLEASE REVIEW THIS AND BELOW: top2 is an array of addresses for strings - %%s is powerful, you dont even have to dereference before passing it to printf - can just pass the address itself!\n\n");
    
    printf("top2 is the name of the array - it is &top2[0], storing the address %p of the first pointer in this array of pointers itself - it is of type char **\n\n", top2); // completely different address
    
    printf("*top2 is the address of the 1st pointer in the array of pointers. it returns address %p with %%p, which is the address of \"Liverpool\" but can return \"Liverpool\" itself with %%s (%s)\n", *top2, *top2);
    printf("top2[0] also returns the address %p with %%p and \"Liverpool\" with %%s (%s)\n\n", top2[0], top2[0]);

    printf("*(*top2) also returns \"L\" (%c) with %%c or ASCII value (%i) with %%i\n\n", *(*top2), *(*top2));
    printf("*top2[0] returns \"L\" (%c) with %%c or ASCII value (%i) with %%i\n", *top2[0], *top2[0]);
    
    printf("*(top2 + 1) is the address of the 2nd pointer in the array of pointers. it returns address %p with %%p, which is the address of \"Man City\" but can return \"Man City\" itself with %%s (%s)\n", *(top2 + 1), *(top2 + 1));
    printf("top2[1] also returns address %p with %%p which is the address of \"Man City\" (note how it is +10 more than top2[0] due to Liverpool\\0) but can return \"Man City\" itself with %%s (%s)\n", top2[1], top2[1]);
    
    printf("*top2[1] returns \"M\" (%c) with %%c or ASCII value (%i) with %%i\n", *top2[1], *top2[1]);
    printf("*(*(top2 + 1)) also returns \"M\" (%c) with %%c or ASCII value (%i) with %%i\n\n", *(*(top2 + 1)), *(*(top2 + 1)));


    // SECTION Pointer to array
    printf("\nPointer to Array eg. \"int (*ptr1)[5];\" and \"char (*ptr2)[15]\n");

    int goals[] = {85, 102, 66, 69, 67};
    int (*pointerToGoals)[5] = &goals;
    printf("5.1.1 int goals[] = {85, 102, 66, 69, 67};\n");
    printf("5.1.2 int (*pointerToGoals)[5] = &goals;\n");
    printf("5.1.3 Address stored in pointerToGoals %p\n", pointerToGoals);
    printf("IMPORTANT: Dereferencing it *pointerToGoals, we get %p - the name of the array goals, which itself is the address\n", *pointerToGoals);

    printf("5.2.1 sizeof(*pointerToGoals) = %li - same as size of goals\n", sizeof(*pointerToGoals));
    printf("5.3.1 Important: *(*(pointerToGoals) + i) Dereferencing it again, we can get the value stored in the address since *pointerToGoals is the name goals\n");
    for (int i = 0; i < 5; i++) {
        printf("5.3.2 value of index %i = %d\n", i, *(*(pointerToGoals) + i));
    };


    // SECTION functions
    printf("\nFunctions\n");
    printf("Calling by value:\n");
    int multiply(int x, int y) {
        printf("5.3.1 Address of x in multiply() = %p\n", &x);
        printf("5.3.2 Address of y in multiply() = %p\n", &y);
        int z;
        z = x * y;
        return z;
    }

    int x = 3, y = 5;
    printf("5.3.3 Address of x in main() = %p\n", &x);
    printf("5.3.4 Address of y in main() = %p\n", &y);
    int product = multiply(x, y);
    printf("5.3.1 Product = %d\n", product);

    printf("\nCalling by reference:\n");
    int multiply2(int *x, int *y) {
        int z;
        z = (*x) * (*y);
        return z;
    }

    int x2 = 3, y2 = 5;
    int product2 = multiply2(&x2, &y2);
    printf("5.3.2 Product2 = %i\n", product2);


    // SECTION pointers as function arguments
    printf("\nPointers as function arguments\n");

    void add(float *a, float *b) {
        float c = *a + *b;
        printf("6.1.2 Addition gives %.2f\n", c); // IMPT note the formatting!
    }

    void subtract(float *a, float *b) {
        float c = *a - *b;
        printf("6.1.2 Subtraction gives %.2f\n", c);
    }

    void multiply3(float *a, float *b) {
        float c = *a * *b;
        printf("6.1.3 Multiplication gives %.2f\n", c);
    }

    void divide(float *a, float *b) {
        float c = *a / *b;
        printf("6.1.4 Division gives %.2f\n", c);
    }

    printf("Enter 2 numbers: \n");
    float a, b;
    scanf("%f %f", &a, &b); // IMPT note the syntax!
    printf("What do you want to do with the numbers?\nAdd: a\nSubtract: s\nMultiply: m\nDivide: d\n");
    char operation = '0';
    scanf(" %c", &operation);
    printf("\nOperating...\n\n");
    switch(operation) { // IMPT syntax
    case 'a':
        add(&a, &b);
        break;
    case 's':
        subtract(&a, &b);
    case 'm':
        multiply3(&a, &b);
    case 'd':
        divide(&a, &b);
    default:
        printf("Invalid Input!!!\n");
    }

    // IMPT passing arrays using 1st element pointer
    printf("\nImportant: Arrays with functions: passing the array name (first element)\n");
    void greatestOfAll(int *p) { // IMPT why not int (*ptr)[5]? because we pass myNumbers and not &myNumbers!
        printf("p is a pointer with address %p\n", p);
        int max = *p;
        printf("*p is the 1st element %i\n", *p);
        for (int i = 0; i < 5; i++) {
            if (*(p + i) > max)
                max = *(p + i);
        }
        printf("The largest element is %d\n", max);
    }
    int myNumbers[5] = {34, 65, -456, 0, 3455};
    greatestOfAll(myNumbers); // IMPT if &myNumbers was passed, argument MUST BE int (*p)[5]

    // SECTION IMPT
    // IMPT passing arrays as the entire pointer &myNumbers
    printf("\nImportant: Arrays with functions: passing the array pointer (& <name>)\n");
    void greatestOfAll2(int (*p)[5]) { // IMPT
        printf("p (&myNumbers2) is the array pointer and dereferencing p (*p) is the array (name) - both pointers with the same address %p == %p\n", p, *p);
        printf("Hence *((*p) + 2): %i == (*p)[2]: %i\n", *((*p) + 2), (*p)[2]);   
        int max = *(*p);

        for (int i = 0; i < 5; i++) {
            if ((*p)[i] > max)
                max = (*p)[i];
        }
        printf("The largest element is %d\n", max);
    }
    int myNumbers2[5] = {34, 65, -456, 0, 3455};
    greatestOfAll2(&myNumbers2); // IMPT


}

