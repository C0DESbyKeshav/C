// A program in C to demonstrate the operations performed on stack (for Turbo C).

#include <stdio.h>
#include <conio.h>
#define MAX 10
int st[MAX], TOP = -1;
// The above line shows that we can even declare and initialize the variables outside the main function. This is called global declaration.

void push(int st[], int val); // F1
int pop(int st[]);            // F2
int peep(int st[]);           // F3
void display(int st[]);       // F4

int main()
{
    int val, option;
    // clrscr();
    do
    {
        printf("\n***** MAIN MENU *****");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");
        printf("\n*********************");
        printf("\n\nEnter your option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\nEnter the number to be pushed on to the stack: ");
            scanf("%d", &val);
            push(st, val); // F1
            break;
        case 2:
            val = pop(st); // F2
            printf("\nThe value deleted from the stack is: %d\n", val);
            break;
        case 3:
            val = peep(st); // F3
            printf("\nThe value stored at the top of the stack is: %d\n", val);
            break;
        case 4:
            display(st); // F4
            break;
        case 5:
            printf("Press Enter to Exit....");
            break;
        default:
            printf("\nEnter a correct operation.");
        }
    } while (option != 5);
    // getch();
    return 0;
}

// F1 => This function pushes (inserts / adds) an element into the stack.
void push(int st[], int val)
{
    // To push an element into the stack, we first need to check if the stack is already full or not.
    if (TOP == MAX - 1)
    {
        printf("\nSTACK OVERFLOW\n");
    }
    else
    {
        TOP++;
        st[TOP] = val;
    }
}

// F2 => This function pops (deletes / removes) an element from the top of the stack.
int pop(int st[])
{
    int val;
    // To pop an element from the top of the stack, we first need to confirm that the stack is not completely empty.
    if (TOP == -1)
    {
        printf("\nSTACK UNDERFLOW\n");
        return -1;
    }
    else
    {
        val = st[TOP];
        TOP--;
        return val;
    }
}

// F3 => This function returns the top most element of the stack to peek.
int peep(int st[])
{
    // It should return a message for the edge case where the stack is empty.
    if (TOP == -1)
    {
        printf("\nSTACK IS EMPTY\n");
        return -1;
    }
    else
        return (st[TOP]);
}

// F4 => This function simply displays all the elements present in the stack.
void display(int st[])
{
    int i;
    // It should return a message for the edge case where the stack is empty.
    if (TOP == -1)
        printf("\nSTACK IS EMPTY\n");
    else
    {
        for (i = TOP; i >= 0; i--)
            printf("\n%d", st[i]);
    }
}
