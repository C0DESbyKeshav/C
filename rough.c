// Fibonacci
/*#include <stdio.h>
#include <conio.h>
int main()
{
    int n, F = 0, S = 1, N;

    //clrscr();
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Sequence:\n");

    for (int i = 1; i <= n; i++)
    {
        printf("%d ", F);
        N = F + S;
        F = S;
        S = N;
    }

    //getch();
    return 0;
}*/

// Even or Odd
/*#include <stdio.h>
#include <conio.h>
int main()
{
    int n;

    //clrscr();
    printf("Enter an integer: ");
    scanf("%d", &n);

    if(n % 2 == 0)
        printf("%d is Even.", n);
    else
        printf("%d is Odd.", n);

    //getch();
    return 0;
}*/

// Prime or not
/*#include <stdio.h>
#include <conio.h>

int main() {
    int n, i, P = 1;

    //clrscr();
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if(n <= 1)
        P = 0;
    else {
        for(i = 2; i < n; i++) {
            if(n % i == 0) {
                P = 0;
                break;
            }
        }
    }

    if(P == 1)
        printf("%d is a Prime number.", n);
    else
        printf("%d is Not a Prime number.", n);

    //getch();
    return 0;
}*/

// Factorial
/*#include <stdio.h>
#include <conio.h>

int main() {
    int n, F = 1;

    //clrscr();
    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    if(n < 0)
        printf("Factorial of a negative number doesn't exist.");
    else {
        for(int i = 1; i <= n; i++) {
            F *= i;
        }
        printf("Factorial of %d = %d", n, F);
    }

    //getch();
    return 0;
}*/

// Factors
/*#include <stdio.h>
#include <conio.h>

int main() {
    int n, i;

    // clrscr();
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    printf("Factors of %d are: ", n);
    for(i = 1; i <= n; i++) {
        if(n % i == 0)
            printf("%d ", i);
    }

    // getch();
    return 0;
}*/

/*#include <stdio.h>

int main() {
    int x = 10, y = 6;
    {
        x = 2;
        printf("%d\n",x);
        printf("%d\n",y);
    }
    {
        y = 4;
        printf("%d\n",x);
        printf("%d\n",y);
    }

    return 0;
}*/

/*
#include <stdio.h>
// #include <conio.h>
#define MAX 10
int queue[MAX];
int front = -1, rear = -1;
void insert(void);
int delete_element(void);
int peek(void);
void display(void);
int main()
{
    int option, val;
    // clrscr();
    do
    {
        printf("\n\n ***********MAIN MENU********");
        printf("\n 1:INSERT AN ELEMENT");
        printf("\n 2:DELETE AN ELEMENT");
        printf("\n 3:PEEK");
        printf("\n 4:DISPLAY AN QUEUE");
        printf("\n 5:EXIT");
        printf("\n ENTER YOUR OPTION:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
            val = delete_element();
            if (val != -1)
                printf("\n THE NUMBER DELETED IS:%d", val);
            break;
        case 3:
            val = peek();
            if (val != -1)
                printf("\n THE FIRST VALUE IN THE QUEUE IS:%d", val);
            break;
        case 4:
            display();
            break;
        }
    } while (option != 5);
    // getch();
    return 0;
}
void insert()
{
    int num;
    printf("\n ENTER THE NUMBER TO BE INSERTED IN THE QUEUE:");
    scanf("%d", &num);
    if (rear == MAX - 1)
        printf("\N OVERFLOW");
    else if (front == -1 && rear == -1)
        front = rear = 0;
    else
        rear++;
    queue[rear] = num;
}
int delete_element()
{
    int val;
    if (front == -1 || front > rear)
    {
        printf("\n UNDERFLOW");
        return -1;
    }
    else
    {
        val = queue[front];
        front++;
        if (front > rear)
            front = rear = -1;
        return val;
    }
}
int peek()
{
    if (front == -1 || front > rear)
    {
        printf("\n QUEUE IS EMPTY");
        return -1;
    }
    else
    {
        return queue[front];
    }
}
void display()
{
    int i;
    printf("\n");
    if (front == -1 || front > rear)
        printf("\n QUEUE IS EMPTY");
    else
    {
        for (i = front; i <= rear; i++)
            printf("\t %d", queue[i]);
    }
}*/