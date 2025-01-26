#include <stdio.h>
// #include<conio.h>
#define size 100

void accept_arr(int arr[size])
{
    int i;
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void display_arr(int arr[size])
{
    int i;
    printf("\nThe elements of the array are:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d\t", i);
    }
}

void replace(int arr[size], int pos, int ele)
{
    int i, loc = pos, elem = ele;
    for (i = 0; i < 5; i++)
    {
        arr[loc] = elem;
    }
}

void main()
{
    // Variable Declaration
    int arr[size], pos, ele;

    // clrscr(); // Clears the previous output screen (conio.h)

    // Input
    printf("Enter the elements of array:\n");
    // Function Calling for accepting the elements of an array
    accept_arr(arr);

    // Output
    // Function Calling for displaying the elements of an array
    display_arr(arr);

    // Replacing the element at user entered Position
    printf("\n\nEnter the position for insertion and deletion: ");
    scanf("%d", &pos);
    printf("\nEnter the element to be inserted: ");
    scanf("%d", &ele);
    // Function Calling for replacing the user entered element in an array at user entered position
    replace(arr, pos, ele);
    // Function Calling for displaying the elements of an array
    display_arr(arr);

    // getch();  // Holds the output screen (conio.h)
}