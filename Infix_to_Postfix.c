// Aim - Write a program to convert Infix expression to Postfix expression.

// * THIS CODE IS NOT COMPLETE YET, IT HAS MANY FLAWS BUT YESSS IT WILL WORK JUST PERFECTLY FOR SOME BASIC INFIX EXPRESSIONS
// * THE FLAWS ARE THERE ONLY BECAUSE I WAS ALSO TRYING TO DO THE CONVERSION ALONG WITH THE FORMATTED OUTPUT
// * AND THE MAIN REASON IS THAT I AM ACTUALLY OUT OF TIME 😅
// * Solved ✅

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define stackSize 50
#define expSize 100

char stack[stackSize];
int top = -1;
char postfix[expSize];

void push(char c)
{
    if (top == stackSize)
    {
        printf("\nStack Overflow\n");
    }
    stack[++top] = c;
}

char pop()
{
    if (top == -1)
    {
        printf("\nStack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int priority(char c)
{
    if (c == '(')
        return 0;
    else if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/' || c == '%')
        return 2;
    return 0;
}

void printStack()
{
    for (int i = 0; i <= top; i++)
        printf("%c", stack[i]);
}

int main()
{
    char infix[expSize], c, index = 0;

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    // printf("\nSTEP 1: Put extra round brackets at the beginning and the end of the expression");
    // for (int i = strlen(infix) - 1; i >= 0; i--)
    //     infix[i + 1] = infix[i];
    // infix[0] = '(';
    // infix[strlen(infix)] = ')';
    printf("\nYour infix expression is: %s", infix);

    printf("\n\nSTEP 2: Find the postfix expression\n\n");
    printf("%-15s %-30s %-35s\n", "Symbol", "Postfix Expression", "Stack");
    printf("----------------------------------------------------------\n");

    for (int i = 0; infix[i] != '\0'; i++)
    {
        // Print the Symbol
        printf("%-15c", infix[i]);

        // for '(' : Push it onto the stack
        if (infix[i] == '(')
        {
            push(infix[i]);
            // To print the entire stack from top to bottom
            printf("%-35s", "");
            printStack();
        }

        // for operators: Push it onto the stack or print is as the postfix expression as per the condition and the rule of conversion
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '%')
        {
            while (priority(stack[top]) >= priority(infix[i]))
            {
                postfix[index++] = pop();
                printf("%-30s", postfix);
            }
            push(infix[i]);
            // To print the entire stack from top to bottom
            printf("%-35s", "");
            printStack();
        }

        // for ')'
        else if (infix[i] == ')')
        {
            while ((c = pop()) != '(')
            {
                postfix[index++] = c;
                printf("%-30s", postfix);
            }
        }

        // for alphabets: if it's an alphabet then directly put it into the array of postfix expression
        else if (isalnum(infix[i]))
        {
            postfix[index++] = infix[i];
            printf("%-30s", postfix);
        }

        printf("\n\n");
    }
    while (top != -1)
    {
        postfix[index++] = pop();
        printf("%-30s", postfix);
    }

    printf("\n\nThe final postfix expression is: %s", postfix);

    return 0;
}
