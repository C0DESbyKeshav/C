#include <stdio.h>
int main()
{
    int num1, num2;
    printf("Enter two numbers:\n");
    scanf("%d%d", &num1, &num2);
    printf("%d + %d = %d \n%d - %d = %d \n%d x %d = %d \n", num1, num2, num1 + num2, num1, num2, num1 - num2, num1, num2, num1 * num2);
    if (num2 != 0)
    {
        printf("%d / %d = %.2f\n%d%%%d = %d \n", num1, num2, (float)num1 / num2, num1, num2, num1 % num2);
    }
    else
    {
        printf("Can't be divided by zero.\n");
    }
    return 0;
}