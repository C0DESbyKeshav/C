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