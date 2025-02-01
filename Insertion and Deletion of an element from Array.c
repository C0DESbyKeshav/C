// A program in C to insert and delete an element from the user-entered array (for Turbo C).

#include <stdio.h>
// #include <conio.h>
#define Max_size 100

/* Here, #include is called the preprocessor directive which inserts the contents of a user-defined or system header file.
Here, stdio and conio is the system header file name.
Here, .h is the extension for the header file.
Here, <> are called the angled brackets.
In this program, printf() and scanf() functions can only be used after including stdio.h
                 clrscr() and getch() functions can be used only after including conio.h
Here, #define is the identifier / preprocessor directive that is used to define macros.*/

// Functions reduces the burden of writing the same block of code more than once in a program.

// FUNCTION DECLARATION
// Syntax: data-type function-name(parameters);
void accept_arr(int, int[]);          // F1
void display_arr(int, int[]);         // F2
void insertion(int, int[], int, int); // F3
void deletion(int, int[], int);       // F4

// When we run the program, O.S calls the main() function.
// void is a non-return data type.
void main()
{
    // Declaration / Initialization of variables
    int arr[Max_size], size, element, pos;
    /* Here, 'arr[Max_size]' is an array of size 'Max_size (i.e 100)
             'size' is the number of elements which will be entered by the user.
             'element' is the number which will be entered by the user for insertion.
             'pos' is the position of any element of array which will be entered by the user for insertion / deletion.
    */

    // clrscr();
    //  clrscr() is a function that CLEARS the previous output SCREEN in Turbo C environment.

    printf("Enter the size of array: ");
    // printf() is a function that prints everything in the same way as written between the double quotes.

    scanf("%d", &size);
    // scanf() is a function that accepts the input from the user and assigns it to some variable.
    // Here, the input given by the user will be assigned to the variable 'size'.
    // %d is the format specifier for integer data type.
    // & (ampersand) represents the address of the variable i.e. the number entered by the user will be directly assigned to the actual variable 'size' present in the memory and not the copy of it.

    printf("Enter the elements of array:\n");
    // Here, '\n' is the Escape Sequence Character which means 'newline' i.e. the cursor automatically goes to the newline to execute the next instruction.

    accept_arr(size, arr); // F1
    // This is called Function Calling which passes two arguments 'size' and 'arr' both of integer types.
    // This line calls the function which is defined in this program and executes the block of code written inside it.

    printf("\nThe elements of array are:\n");
    display_arr(size, arr); // F2
    printf("\n\nEnter an element: ");
    scanf("%d", &element);
    printf("Enter a position of array for insertion: ");
    scanf("%d", &pos);

    pos -= 1;
    // This line means pos = pos - 1
    // This is done because not every user knows that the index number of an array starts from 0.
    // To make it easy for all the users to select a position of the array to insert a new element.

    printf("\nAfter inserting %d at position %d, the array becomes:\n", element, pos + 1);
    insertion(size, arr, element, pos); // F3
    printf("\n\nEnter a position of array for deletion: ");
    scanf("%d", &pos);
    pos -= 1;
    printf("\nAfter deleting %d from position %d, the array becomes:\n", arr[pos], pos + 1);
    deletion(size, arr, pos); // F4

    // getch();
    //  getch() is a function that holds the current output being displayed on the output screen in Turbo C environment.
}

// FUNCTION DEFINITION

// F1 => This function accepts the elements of an array from the user.
void accept_arr(int size, int arr[]) // F1
{
    int i;
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    /* for loop is one of the types of loops defined in C.
    Loops are used to repeat the desired lines of code, till desired number of times.
    Syntax: for(initialization; condition; incrementation/decrementation)
    /          { ..............instructions............... }
    The flow of loops starts from the initialization part which is executed only once.
    After that it checks the condition part and after executing the block of instructions inside, at the end it executes the incrementation / decrementation part.*/
}

// F2 => This function displays the elements of an array.
void display_arr(int size, int arr[]) // F2
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
        // Here '/t' is the Escape Sequence Character which means 'tab' which prints a single horizontal tab on the output screen.
    }
}

// F3 => This function inserts an user-entered element into the array at the user-entered position.
void insertion(int size, int arr[], int element, int pos) // F3
{
    int i;
    for (i = size - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    // As we insert a new element into the array, the other elements (on the right side from the selected position) should first shift one position towards the right.

    arr[pos] = element;
    // Insertion of the user-entered element at the user-entered position.

    for (i = 0; i < size + 1; i++)
    {
        printf("%d\t", arr[i]);
    }
    // Displaying the element of the updated array.
}

// F3 => This function deletes an element from the array from the user-entered position.
void deletion(int size, int arr[], int pos) // F4
{
    int i;
    for (i = pos; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    // To delete an element from the array, the other elements (on the right side from the selected position) should shift one position towards the left.

    for (i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    // Displaying the element of the updated array.
}