/* C is one of the oldest and most fundamental programming languages, and it is extensively used all over the world.
   C is a fast, portable language with a large library.
   It's the Mother of all programming languages
*/

// Dennis Ritchie developed the C programming language between 1972 and 1973 at Bell Laboratories.

// This is a comment. It's ignored by the compiler. It's for our understanding. It's written after two backslashes.

/* This
   is a
   multi-line comment
   It's written under backslash(/) and asterick(*)
*/

/*
    # is preprocessor directive.
    'include' is a keyword. Keywords are case sensitive. i.e. We can't write 'INCLUDE' it will throw an error. It has to be 'include'.
    Content inside <> is a header file by which we can include the functions supported by those header files in the program.
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*                          DATA TYPES
                                |
       _________________________|_______________________
      |              |                 |               |
    BASIC         DERIVED          ENUMERATION       Void
    1. int         1. array          1. enum         1. void
    2. float       2. pointers
    3. double      3. structure
    4. char        4. union
*/

// Structure declaration:
struct Student // S1
{
    char name[30];
    int roll_no;
    float marks;
}; // semicolon is most important here

typedef struct Employee // S2
{
    char name[30];
    int id_no;
    float salary;
} Emp;

typedef struct vector // S3
{
    int i, j;
} vec;

typedef struct Complex // S4
{
    int real, img;
} cx;

typedef struct Date // S5
{
    int dd, mm, yyyy;
} date;

// Function Prototype - informs the compiler about a function that the function which are created below will be defined later in the program. It's not mandatory. We can directly define the function without declaring its prototype.
int Addition(int, int);                   // F1
int factorial(int);                       // F2
float average(int, int, int);             // F3
float C2F(float);                         // F4
float Force(int);                         // F5
int fibonacci(int);                       // F6
int Sum(int);                             // F7
void Pattern1(int);                       // F8
int cbv_change(int);                      // F9
int cbf_change(int *);                    // F10
void Swap(int *, int *);                  // F11
void print_array(int[], int);             // F12
void ReverseArray(int[], int);            // F13
int PositiveCounter(int[], int);          // F14
void x_arr(int l, int a[][10], int t[]);  // F15
int Strlen(char[]);                       // F16
void Slice(char[], int, int);             // F17
void Strcpy(char[], char[]);              // F18
void display_structure(struct Student s); // F19
void sumVector(vec v1, vec v2);           // F20
int CompareDates(date d1, date d2);       // F21

// Function definition
int Addition(int x, int y) // F1
{                          // x and y are parameters
    printf("Sum of %d and %d = %d\n", x, y, x + y);
    return 0;
}

int factorial(int n) // F2
{
    // factorial(5) = 1 x 2 x 3 x 4 x 5
    // factorial(4) = 1 x 2 x 3 x 4
    // factorial(3) = 1 x 2 x 3
    // factorial(n-1) = 1 x 2 x 3 x .... x n-1
    // factorial(n) = 1 x 2 x 3 x .... x n-1 x n
    // factorial(n) = factorial(n-1) x n

    // factorial(1) = 1
    // factorial(0) = 1

    if (n == 1 || n == 0) // Base Condition
    {
        return 1;
    }

    return factorial(n - 1) * n;
    // For Factorial of 3:
    // factorial(2)       x 3
    // [factorial(1) x 2] x 3
    // [    1      ] x 2  x 3
    // = 6
}

float average(int a, int b, int c) // F3
{
    return (a + b + c) / 3.0; // If we divide the expression by '3' instead of '3.0' then it will give an incorrect value.
}

float C2F(float C) // F4
{
    /* To convert Celsius to Fahrenheit, formula:
    Fahrenheit = (((9 x C) / 5) + 32) */
    return (((9 * C) / 5) + 32);
}

float Force(int mass) // F5
{
    /* F = m x a
    where,  F = Force applied on the body
            m = mass of the body
            a = acceleration due to gravity of the body */
    return (mass * 9.8);
}

int fibonacci(int n) // F6
{
    // Fibonacci Sequence logic:
    // finonacci(n) = fibonacci(n-1) + fibonacci(n-2)

    if (n == 1 || n == 2)
    {
        return n - 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
    /* ex.: if n = 5
    fibonacci(5) =         fibonacci(4)                           +         fibonacci(3)
                 = [        fibonacci(3)          + fibonacci(2)] + [fibonacci(2) + fibonacci(1)]
                 = [[fibonacci(2) + fibonacci(1)] +      1      ] + [     1       +      0      ]
                 = [      1       +      0      ] +      1      ] + [     1       +      0      ]
                 = 1 + 0 + 1 + 0 + 1 + 1 + 0
    fibonacci(5) = 3
    */
}

int Sum(int n) // F7
{
    if (n == 1) // Base Condition
    {
        return 1;
    }
    return n + Sum(n - 1); // This line of code is same as that of factorial() function
}

void Pattern1(int n) // F8
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i + count; j++)
        {
            printf("* ");
        }
        printf("\n");
        count++;
    }
}

int cbv_change(int a) // F9
{
    a = 5;
    return a;
}

int cbf_change(int *a) // F10
{
    *a = 5;
    return *a;
}

void Swap(int *a, int *b) // F11
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int arr[], int n) // F12
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void ReverseArray(int arr[], int n) // F13
// If you define arr[5], it will throw an error. Define arr[] to avoid any errors.
{
    /* Method I: Reversing the array with the help of a second array
    int temp[n], j = 0;
    for (int i = (n - 1); i >= 0; i--)
    {
        temp[j] = arr[i];
        j++;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    } */

    /* Method II : Reversing the array by swapping the elements */
    int temp;
    for (int i = 0; i < n / 2; i++)
    {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

int PositiveCounter(int a[], int n) // F14
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            count++;
        }
    }
    return count;
}

void x_arr(int l, int a[][10], int t[]) //  F15
// If you define a[][], it will throw an error. Define a[][10] to avoid any errors.
// Declaration of 'a' as multidimensional array must have bounds for all dimensions except the first.
{
    for (int j = 0; j < l; j++)
    {
        printf("The table of %d:\n", t[j]);
        for (int k = 0; k < 10; k++)
        {
            a[j][k] = t[j] * (k + 1);
            printf("%d x %d = %d\n", t[j], k + 1, a[j][k]);
        }
        printf("\n");
    }
}

int Strlen(char name[]) // F16
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void Slice(char str[], int s, int e) // F17
{
    int j = 0, k = (e - s) + 1;
    char sliced[k];
    for (int i = s - 1; i < e; i++)
    {
        sliced[j] = str[i];
        j++;
    }
    printf("\nThe sliced string is: %s", sliced);
}

void Strcpy(char str1[], char str2[]) // F18
{
    for (int i = 0; str2[i] != '\0'; i++)
    {
        str1[i] = str2[i];
    }
}

void display_structure(struct Student s) // F19
{
    printf("Student Details:\nName: %s\nRoll Number: %d\nTotal marks obtained: %.2f\n\n", s.name, s.roll_no, s.marks);
}

void sumVector(vec v1, vec v2) // F20
{
    int sumi = v1.i + v2.i, sumj = v1.j + v2.j;
    printf("\nSum of both the vectors = %di + %dj", sumi, sumj);
}

int CompareDates(date d1, date d2)
{
    /* Logic :
    If d1 > d2 then return 1
    If d1 < d2 then return -1
    If d1 = d2 then return 0 */

    if ((d1.yyyy == d2.yyyy) && (d1.mm == d2.mm) && (d1.dd == d2.dd))
    {
        return 0;
    }
    else if (d1.yyyy > d2.yyyy)
    {
        return 1;
    }
    else if (d1.yyyy < d2.yyyy)
    {
        return -1;
    }
    else if (d1.mm > d2.mm)
    {
        return 1;
    }
    else if (d1.mm < d2.mm)
    {
        return -1;
    }
    else if (d1.dd > d2.dd)
    {
        return 1;
    }
    else if (d1.dd < d2.dd)
    {
        return -1;
    }

    return 0; // Just to avoid the warning "control reaches end of non_void function [-Wreturn-type]" after the compilation of program.
}

int main() // main function
{
    // printf() FUNCTION:
    printf("Hello Keshav!");
    /* 'printf' is same as 'cout' in C++.
    It prints whatever the content is inside the double inverted commas.*/

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // FORMAT SPECIFIERS FOR DATA TYPES:
    /*  %d for integers
        %c for characters
        %f for real values
        %lf for double
        %p for pointers
        %u for unsigned int
        %s for strings
    */

    int a = 1; // Variable declaration and initialization.
    char b = 'K';
    float c = 9.5;
    double d = 9.7643576523764351;

    printf("Integer value= %d\n", a);
    printf("Character value= %c\n", b);
    printf("Decimal number = %f\n", c);          // After decimal 6 digits
    printf("Double data type value = %lf\n", d); // After decimal 6 digits

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // SYNTAX FOR scanf() FUNCTION:
    /*  int i;
      printf("Enter a number:\n");
      scanf("%d", &i);  // &(ampersand) is the address operator.
      printf("Your input is %d.\n",i);

    printf("\n\n------------------------------------------------------------------------------------\n\n");
    */

    // sizeof KEYWORD:
    printf("Size of int data type is %zu bytes.\n", sizeof(int));
    printf("Size of char data type is %zu byte.\n", sizeof(char));
    printf("Size of float data type is %zu bytes.\n", sizeof(float));
    /* Size of char data type is always 1
    whereas size of int and float data types may change as per the operating system we are currently working on.*/

    /* In C language, %zu is a format specifier used with the printf and scanf functions to handle the size_t data type.
    What is size_t?
    size_t is an unsigned integer type defined in the stddef.h header file.
    It's used to represent the size of objects in memory.
    The exact size of size_t can vary depending on the system architecture, but it's guaranteed to be large enough to hold the size of any object in memory.*/

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // USE OF stdlib OR stddef LIBRARY TO PRINT SIZE OF DATA TYPES :

    size_t size1 = sizeof(int), size2 = sizeof(char), size3 = sizeof(float);

    printf("Size of int data type is %zu bytes.\n", size1);
    printf("Size of char data type is %zu byte.\n", size2);
    printf("Size of float data type is %zu bytes.\n", size3);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // ESCAPE SEQUENCE CHARACTERS:
    printf("Beep Sound \a");
    printf("\n");
    printf("Back\bspace");
    printf("\n");
    printf("Form Feed page break here \f continue text"); // might work
    printf("\n");
    printf("Re \r turn"); // Prints "turn" // might work
    printf("\n");
    printf("Print \\");
    printf("\n");
    printf("Print \101"); // Prints 'A' which is 101 in octal.
    printf("\n");
    printf("Print \x41"); // Prints 'A' which is 41 in hexadecimal.
    printf("\n");
    printf("Termi\0nate"); // Null character is used to terminate a string.
    printf("\n");
    printf("New \n line");
    printf("\n");
    printf("Tab \t space");
    printf("\n");
    printf("Print \" Double inverted \" commas");
    printf("\n");
    printf("Print \' Single inverted \' commas");
    printf("\n");
    printf("Print \\ or \\n or \\t without activating it");
    printf("\n");

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // AREA OF RECTANGLE:
    int length = 5, breadth = 4;
    printf("Length = %d cm\nBreadth = %d cm\nThe Area of Rectangle = %d sq.cm.\n", length, breadth, (length * breadth));

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // AREA OF CIRCLE & VOLUME OF CYLINDER:
    int radius = 5, height = 3;
    printf("Radius = %d cm\nThe Area of Circle = %f sq.cm.\n", radius, 3.14 * radius * radius);
    printf("\nThe Volume of Cylinder with radius %d cm & height %d cm = %f cu.cm.", radius, height, 3.14 * radius * radius * height);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // CELCIUS TO FAHRENHEIT:
    float C = 37.0, F;
    printf("%f Celcius = %f Fahrenheit.\n", C, ((9.0 / 5.0) * C) + 32); // If we divide 9/5 instead of 9.0/5.0 then it will give an int value but we want float value.

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // SIMPLE INTEREST:
    float p = 34.1;
    int r = 8;
    int t = 5;
    printf("The Simple interest for principal amount %f , annual rate of interest %d , time period %d years is %f.\n", p, r, t, (p * r * t) / 100);

    // TYPE CONVERSIONS:
    /* Result for any arithmetic operations:
      1. int type with int type = int type result
      2. float type with int or float type = float type result
      Example:
        5/2 = 2
        5.0/2 = 2.5
        5.0/2.0 = 2.5
        2/5 = 0
    */

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // TYPES OF OPERATORS:
    /*  1. Arithmetic
        2. Relational
        3. Logical
        4. Assignment
        5. Unary
        6. Conditional
        7. Special
        8. Bitwise
        9. Shift
    */

    // % OPERATOR:
    /*  1. Modular Division Operator
        2. Returns the Remainder
        3. Cannot be applied on float
        4. Sign is same as that of numerator
    */
    int A = 10;
    printf("The value of 10%3 = %d", a % 3);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // OPERATOR PRECEDENCE AND ASSOCIATIVITY:
    /*  C language does NOT automatically assumes the BODMAS rule.

        Operator Priority list:
        1st :       * / %
        2nd :       + -
        3rd :       =

        Operators of higher priority are evaluated first in the absence of parentheses.

        When operators of equal priority are present in an expression, the tie is taken care of associativity.
        x*y/z ----> (x*y)/z
        x/y*z ----> (x/y)*z
        /,* follows left to right associativity.

        *NOTE: Always use parentheses to avoid confusion.
    */
    int x = 3, y = 6, z = 9;
    printf("The result of operation as per the operator precedence & associativity = %d", 3 * y / 2 * z + 7 * x);
    /*
    3*y/2*z+7*x
    3*6/2*9+7*3
    18/2*9+21
    9*9+21
    81+21
    102
    */

    /*
         Priority         Operator
           1st               !
           2nd              *,/,%
           3rd               +,-
           4th             <>,<=,>=
           5th              ==,!=
           6th               &&
           7th               ||
           8th               =
    */

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // CONTROL INSTRUCTIONS:
    /*
    Determines the flow of control in a program. There are 4 types of control instructions in C:
    1. Sequence Control Instructions : Step by step execution of instructions one after another in a simple program.
    2. Decision Control Instructions : Executes the next instruction based upon if the condition is true or not like 'if', 'else', switch'.
    3. Loop Control Instructions : Loops like 'for', 'while', 'do - while'.
    4. Case Control Instructions : 'switch case'.
    */

    // TYPECASTING:
    int n = 45;
    float m = 32.23;
    printf("Float data type value = %f\n", m);
    n = (int)m; // Converts the float data type to integer.
    printf("After conversion of float type variable to integer type:\nVariable value = %d", n);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // DECISION MAKING INSTRUCTIONS:
    /*
    1. if-else statement
    2. switch statement
    */
    int age = 5;
    if (age > 10)
    {
        printf("Your age is greater than 10\n");
    }
    else
    {
        printf("Your age is not greater than 10\n");
    }
    if (age % 5 == 0)
    {
        printf("Your age is divisible by 5\n");
    }
    if (1) //* if (true) then execute the statement. Here true means any non-zero value.
    {
        printf("Executed!\n");
    }
    if (2.74)
    {
        printf("Executed!\n");
    }
    if ('c')
    {
        printf("Executed!\n");
    }
    if (0)
    {
        printf("Not Executed!\n");
    }

    int Age = 45;
    if (Age > 60)
    {
        printf("You can drive and you are a senior citizen.\n");
    }
    else if (Age > 40)
    {
        printf("You can drive and you are elder.\n");
    }
    else if (Age > 18)
    {
        printf("You can drive.\n");
    }
    else
    {
        printf("You cannot drive.\n");
    }

    /*
    NOTE:
    1. Using if-else if-else reduces indents.
    2. The last "else" is optional.
    3. Also there can be any number of "else if".
    4. Last else is executed only if all conditions fail.
    */

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // RELATIONAL OPERATORS:
    /*
    Used to evaluate conditions (true or false) inside the if statements.
    Some examples of relational operators:
    ==, =>, >, <, <=, !=
    *NOTE: '=' is used for asssignment whereas '==' is used for equality check.
    The condition can be any valid expression. In C a non-zero value is considered to be true.
    */

    // LOGICAL OPERATORS:
    /*
    1. && (AND) --> is true when both the conditions are true
        a. "1 and 0" is evaluated as false.
        b. "0 and 0" is evaluated as false.
        c. "1 and 1" is evaluated as true.
    2. || (OR) --> is true when at least one of the conditions is true. (1 or 0 -> 1) (1 or 1 -> 1)
    3. ! (NOT) --> returns true if given false and false if given true
        a. !(3==3) --> evaluates to false.
        b. !(3>30) --> evaluates to true.

    As the number of conditions increases, the level of indentation increases. This reduces the readability. Logical operators come to rescue in such cases.
    */
    int I = 1, J = 1;

    if (I && J)
    {
        printf("Both are True\n");
    }
    // is same as writing ....
    if (I)
    {
        if (J)
        {
            printf("Both are True\n");
        }
    }

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // CONDITIONAL OPERATORS:
    /* A shorthand "if-else" can be written using the CONDITIONAL or TERNARY operators */
    int l = 345, o = 32;
    l > o ? printf("l is greater") : printf("o is greater");

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // SWITCH CASE CONTROL INSTRUCTION:
    int Z = 2;
    switch (Z)
    {
    case 3:
        printf("Case 3\n");
        break;
    case 2:
        printf("Case 2\n");
        break;
    case 4:
        printf("Case 4\n");
        break;
    case 1:
        printf("Case 1\n");
        break;
    default:
        printf("Nothing matched\n");
    }

    /* Break Statement:
        The 'break' statement is used to exit the loop irrespective of whether the condition is true or false.
        Whenever  a 'break' is encountered inside the loop, the control is sent outside the loop.
    */

    /* Continue Statement:
        The block of code after 'continue' will be skipped and the next iteration of loop will be executed.
    */

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Find grade of a student based on his marks
        90-100 => A
        80-90  => B
        70-80  => C
        60-70  => D
        50-60  => E
        <50   => F
    */
    char grade;
    int marks = 46;

    if (marks <= 100 && marks >= 90)
    {
        grade = 'A';
    }
    else if (marks <= 90 && marks >= 80)
    {
        grade = 'B';
    }
    else if (marks <= 80 && marks >= 70)
    {
        grade = 'C';
    }
    else if (marks <= 70 && marks >= 60)
    {
        grade = 'D';
    }
    else if (marks <= 60 && marks >= 50)
    {
        grade = 'E';
    }
    else
    {
        grade = 'F';
    }

    printf("Your grade at %d marks is %c", marks, grade);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /*
    Determine whether a student has passed or failed.
    To pass, a student requires a total of 40% and atleast 33% in each subject.
    Assume there are three subjects and take the marks as input from the user.
    */
    int marks1, marks2, marks3;

    if (marks1 < 33 || marks2 < 33 || marks3 < 33)
    {
        printf("You have failed due to less marks in individual subject(s).\n");
    }
    else if (((marks1 + marks2 + marks3) / 3) < 40)
    {
        printf("You have failed due to less percentage.\n");
    }
    else
    {
        printf("You have passed!\n");
    }

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /*
    Calculate income tax paid by an employee to the government as per the slabs mentioned below:
            Income Slab         Tax
            2.5L - 5.0L         5%
            5.0L - 10.0L        20%
            Above 10L           30%
    Note that there is no tax below 2.5L
    */
    int income = 530700;
    float tax = 0;

    if (income <= 250000)
    {
        tax = 0;
    }
    else if (income > 250000 && income <= 500000)
    {
        tax = 0.05 * (500000 - 250000) + 0.02 * (income - 500000);
    }
    else
    {
        tax = 0.05 * (500000 - 250000) + 0.02 * (1000000 - 500000) + 0.03 * (income - 1000000);
    }
    printf("Total tax you have to pay = %.2f\n", tax); // Only 2 digits after decimal

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Find whether a year is a leap year or not.*/
    int year = 2024;

    if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
    {
        printf("%d is a leap year", year);
    }
    else
    {
        printf("%d is not a leap year", year);
    }

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Determine whether a character is lowercase or not*/
    char ch1 = 'K', ch2 = 'k';
    //* If the ASCII value of any character is from 97 to 122 then it is a lowercase character.

    printf("The ASCII value of character %c = %d\n", ch1, ch1);
    printf("The ASCII value of character %c = %d\n", ch2, ch2);

    if (ch1 >= 97 && ch1 <= 122)
    {
        printf("%c is a lowercase character.\n", ch1);
    }
    else
    {
        printf("%c is not a lowercase character.\n", ch1);
    }
    if (ch2 >= 97 && ch2 <= 122)
    {
        printf("%c is a lowercase character.\n", ch2);
    }
    else
    {
        printf("%c is not a lowercase character.\n", ch2);
    }

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Find greatest of four numbers*/
    int num1 = 0, num2 = 9, num3 = 6, num4 = 2;

    if (num1 > num2 && num1 > num3 && num1 > num4)
    {
        printf("%d is the greatest of four numbers.", num1);
    }
    if (num2 > num1 && num2 > num3 && num2 > num4)
    {
        printf("%d is the greatest of four numbers.", num2);
    }
    if (num3 > num1 && num3 > num2 && num3 > num4)
    {
        printf("%d is the greatest of four numbers.", num3);
    }
    if (num4 > num1 && num4 > num2 && num4 > num3)
    {
        printf("%d is the greatest of four numbers.", num4);
    }

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // INCREMENT / DECREMENT OPERATOR:
    /*  i++ print i first & then increments i (Post increment Operator)
        ++i increments i first & then prints i (Pre increment Operator)*/

    int R = 0;
    printf("Initial value of R = %d\n", R); // R = 0
    printf("R++ = %d\n", R++);              // R = 0
                                            // R = 1
    printf("++R = %d\n", ++R);              // R = 2

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // COMPOUND ASSIGNMENT OPERATOR:
    int Q = 0;
    printf("Initial value of Q = %d\n", Q); // Q = 0
    printf("Q += 2  =  %d\n", Q += 2);      // Q = Q + 2    // Q = 0 + 2 = 2
    printf("Q -= 1  =  %d\n", Q -= 2);      // Q = Q - 2    // Q = 2 - 1 = 1
    printf("Q *= 2  =  %d\n", Q *= 2);      // Q = Q * 2    // Q = 1 * 2 = 2
    printf("Q /= 2  =  %d\n", Q /= 2);      // Q = Q / 2    // Q = 2 / 2 = 1
    printf("Q %= 2  =  %d\n", Q %= 2);      // Q = Q % 2    // Q = 1 % 2 = 0

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // LOOP CONTROL INSTRUCTIONS:
    /*
    There are three types of loops in C language:
        1. while loop
        2. do-while loop
        3. for loop
    */

    // while LOOP:
    int P = 1;
    printf("while loop:\n");
    while (P <= 4)
    {
        printf("%d. Hello Keshav\n", P);
        P++; // This is an increment operator (P++ means P=P+1)
    }

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // do-while LOOP:
    /* The do-while loop works very similar to while loop.
        1. 'while' checks the condition & then executes the code.
        2. 'do-while' executes the code & then checks the condition.
    */
    int S = 1;
    printf("do-while loop:\n");
    do
    {
        printf("The value = %d\n", S);
        S++;
    } while (S <= 3); // Here, semicolon is very important.

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // for LOOP:
    printf("for loop:\n");
    for (int G = 1; G <= 5; G++)
    {
        printf("Value = %d\n", G);
    }

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Program to print multiplication of number 7:*/
    printf("Table of 7:\n");
    for (int O = 1; O <= 10; O++)
    {
        printf("7 x %d = %d\n", O, 7 * O);
    }

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Program to print multiplication table of 9 in reversed order:*/
    printf("Table of 9:\n");
    for (int O = 10; O > 0; O--)
    {
        printf("9 x %d = %d\n", O, 9 * O);
    }

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Program to sum first ten natural numbers using while loop:*/
    int L = 1, sum = 0;
    while (L <= 10)
    {
        sum = sum + L;
        L++;
    }
    printf("Sum of first ten natural numbers = %d\n", sum);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Program to calculate the sum of the numbers ocurring in the multiplication table of 8 (Consider 8x1 to 8x10):*/
    int res = 0;
    for (int O = 1; O <= 10; O++)
    {
        res = res + (8 * O);
    }
    printf("Sum of numbers occuring in the multiplication table of 8 = %d\n", res);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Program to calculate the factorial of number 5 using a for loop:*/
    int fact = 1;
    for (int O = 1; O <= 5; O++)
    {
        fact = fact * O;
    }
    printf("The factorial of 5 = %d\n", fact);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Program to check whether a number is prime or not:*/
    int U = 17, counter = 0;
    if (U > 1)
    {
        for (int O = 1; O <= U; O++)
        {
            if (U % O == 0)
            {
                counter++;
            }
        }
        if (counter == 2)
        {
            printf("%d is a prime number\n", U);
        }
        else
        {
            printf("%d is NOT a prime number\n", U);
        }
    }
    else
    {
        printf("%d is NOT a prime number\n", U);
    }

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // FUNCTION:
    int number_1 = 5, number_2 = 7;
    Addition(number_1, number_2); // F1

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // RECURSION:
    /*  1. Recursion is often a direct way to implement certain algorithms, but not always the most direct for every algorithm.
        2. The condition in a recursive function that stops further recursion is called the base case.
        3. Sometimes, due to an oversight by the programmer, a recursive function can continue to run indefinitely without reaching a base class, potentially causing a stack overflow or memory error.
    */
    int FACT = 3;
    printf("The factorial of %d is %d\n", FACT, factorial(FACT)); // F2

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write a program using function to find average of three numbers. */
    int avg1 = 4, avg2 = 1, avg3 = 2;
    printf("The average of numbers 4, 1 and 2 is %.2f", average(avg1, avg2, avg3)); // F3

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write a function to convert Celsius temperature into Fahrenheit. */
    float Celsius = 45.00;
    printf("%f Celsius = %.2f Fahrenheit", Celsius, C2F(Celsius)); // F4

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write a function to calculate force of attraction on a body of mass 'm' exerted by earth. Consider g = 9.8 m/s sq. */
    int mass = 5;
    printf("Force of attraction on a body of mass %d kg = %.2f N", mass, Force(mass)); // F5

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write a program using recursion to calculate nth element of Fibonacci series. */
    /* Fibonacci Series: First two numbers are fixed 0 and 1, after that from 3rd number, each number is the addition of previous two numbers
        ex.: 3rd number = 1 = 0 + 1, 4th number = 2 = 1 + 1, 5th number = 3 = 2 + 1, 6th number = 5 = 2 + 3, ....
    0, 1, 1, 2, 3, 5, 8, 13, 21, 34, .... */
    int nth_element = 10;
    printf("The %dth element of fibonacci sequence = %d", nth_element, fibonacci(nth_element)); // F6

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* What will the following line produce in a C program: */
    int increment_test = 4;
    printf("a = %d\n++a = %d\na++ = %d", increment_test, ++increment_test, increment_test++);

    /* Expected Output:
    a = 4      // Prints the variable as it is.
    ++a = 5    // First increments then prints.
    a++ = 5    // First prints then increments. */

    /* Actual Output:
    a = 6
    ++a = 6
    a++ = 4
    This is because the evaluation order(right to left) & printing order(left to right) is different of the compiler for a printf() function.

    //* NOTE: BOTH THE ANSWERS ARE CORRECT. IT DEPENDS ON THE TYPE OF COMPILER.

    So, the actual order of operation behind the scenes is:
    a++ = 4    // First prints then increments.
    ++a = 6    // First increments then prints.
    a = 6      // Prints the variable as it is.
    And,the printing order is a, ++a, a++*/

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write a recursive function to calculate the sum of first 'n' natural numbers.*/
    int limit = 100;
    if (n > 0)
    {
        printf("The Sum of first %d natural numbers = %d", limit, Sum(limit)); // F7
    }
    else
    {
        printf("The number you have entered is NOT a natural number");
    }

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write a program using function to print the following pattern (first n lines)

    *
    * * *
    * * * * *

    Here, n = 3. So, the pattern will be printed till 3 lines.
    */
    int limit_pattern = 3;
    Pattern1(limit_pattern); // F8

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // POINTERS:
    /* A pointer is a variable which stores the address of another variable. */
    /* THE "ADDRESS OF" (&) OPERATOR:
    The address of operator is used to obtain the address of a given variable. */

    int address_of = 72;
    printf("The address of a = 72 is %p\n", &address_of); // in hexadecimal
    printf("The address of a = 72 in integer form is %u\n", &address_of);

    int f = 24;
    int *ptr1 = &f; // 'ptr1' is a pointer pointing to 'f' which means it stores the address of variable 'f'.
    printf("\nThe address of f = 24 is %p\n", &f);
    printf("The address of f = 24 is %p\n", ptr1);

    /* THE 'VALUE AT ADDRESS' OPERATOR (*):
    The value at address or * operator is used to obtain the value presentg at a given memory address. It is denoted by *
    *(&f) = 24
    */

    printf("\nThe value at the address of f = %d\n", *(&f));

    // Just like pointer to type integer, we also have pointers to char, float, etc.
    int *int_ptr;   // pointer to integer
    int *char_ptr;  // pointer to character
    int *float_ptr; // pointer to float

    // NOTE: * and & cancel out each other.

    /* POINTER to POINTER:*/
    f = 45;
    int *ptr2 = &f;
    int **ptr3 = &ptr2;
    int ***ptr4 = &ptr3;
    printf("\nThe address of f = %p\n", ptr2);
    printf("The address of ptr2 = %p\n", ptr3);
    printf("The address of ptr3 = %p", ptr4);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // TYPES OF FUNCTION CALL:
    /* Based on the way we pass arguments to the function, function calls are of two types:
         1. Call by value -> Sending the values of arguments.
         2. Call by reference -> Sending the address of arguments.
     */

    // Call by value:
    int cbv = 1;
    printf("Before executing function: a = %d", cbv);
    printf("\nIn function: a = %d", cbv_change(cbv)); // F9
    printf("\nAfter executing function: a = %d\n", cbv);
    /* cbv_change() mein 'cb' variable pass nhi ho rahi hai. 'cb' variable ki copy pass ho rahi hai. So, cbv_change() cannot change the value of 'cb'. */

    // Call by reference:
    int cbf = 2;
    printf("\nBefore executing function: a = %d", cbf);
    printf("\nIn function: a = %d", cbf_change(&cbf)); // F10
    printf("\nAfter executing function a = %d", cbf);
    /* cbf_change() mein 'cbf' variable pass ka address pass ho raha hai. So, cbf_change() WILL change the value of 'cbf'. */

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // SWAPPING OF TWO NUMBERS USING FUNCTION:
    int s1 = 4, s2 = 6;
    printf("Before Swapping:\na = %d, b = %d\n", s1, s2);
    Swap(&s1, &s2); // F11   /* called by reference */
    printf("\nAfter Swapping:\na = %d, b = %d\n", s1, s2);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // ARRAYS:
    /* An array is a collection of similar elements. Array allows a single variable to store multiple values.
    Initialization of array:
    int a[3] = {2, 7, 0};
    OR
    int a[] = {2,6,8,9}; */

    // OPERATIONS ON POINTERS:
    /* Following operations can be performed on a pointer:
        1. Addition of a number to a pointer.
        2. Subtraction of a number from a pointer.
        3. Subtraction of one pointer from another.
        4. Comparison of two pointer variables.
    */

    // NOTE: If a pointer is incremented by 1 toh uska matlab yeh NAHI hai ki woh 771 se 772 hoga. Uska yeh matlab hai yeh hai ki woh 1 kadam aagey badhega which means 4 bytes (depends on the hardware artitechture we are working on) se badhega, 2 kadam aagey badhna matlab 8 bytes se aagey badhega.

    // PRINT ARRAY USING POINTER:
    int arr_marks[] = {12, 24, 36, 48};
    int *arr_ptr = arr_marks; // Same as int* arr_ptr = &arr_marks[0];

    for (int i = 0; i < 4; i++)
    {
        printf("The marks at index %d is %d\n", i, *arr_ptr);
        arr_ptr++;
    }

    /* Array can also be passed as a function argument. */

    // MULTIDIMENSIONAL ARRAYS
    /* An array can be of 2 dimension / 3 dimension / n dimensions. */

    /* A 2 dimension array can be defined like this:
       int arr[3][2] = {1, 4, 7, 9, 11, 22};
       * Indexing ----> 00 01 10 11 20  21
       * Range --> i= from 0 to 2,   j= from 0 to 1
       We can acces the elements of this array as arr[0][0], arr[0][1] & so on ...
    */

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Create an array of 10 numbers. Verify using pointer arithmetic that (ptr+2) points to the third element where ptr is a pointer pointing to the first element of the array. */
    int arr_10[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, *ptr_arr_10 = arr_10;
    printf("The element at index 3 is %d\n", *(ptr_arr_10 + 2));

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write a program to create an array of 10 integers and store multiplication table of 5 in it. */
    int m_arr[10];
    for (int i = 1; i <= 10; i++)
    {
        m_arr[i] = 5 * i;
        printf("5 x %d = %d\n", i, m_arr[i]);
    }

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write a program containing a function which reverses the array passed to it. */
    int p_arr[] = {1, 2, 3, 4, 5}, arr_size = 5;

    printf("Before reversing the array:\n");
    print_array(p_arr, arr_size); // F12

    ReverseArray(p_arr, arr_size); // F13    // If you pass p_arr[5] or p_arr[], it will throw an error. You have to pass p_arr to avoid any errors.

    printf("\nAfter reversing the array:\n");
    print_array(p_arr, arr_size); // F12

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write a program containing functions which counts the number of positive integers in an array. */
    int pos_arr[5] = {0, -1, 2, 6, -3}, pos_arr_size = 5;
    print_array(pos_arr, pos_arr_size);                                                                           // F12
    printf("There are total of %d positive numbers in the above array.", PositiveCounter(pos_arr, pos_arr_size)); // F14

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Create an array of size 3 x 10 containing multiplication tables of the numbers 2, 7 & 9 respectively. */
    int size_ma = 3, multi_arr[size_ma][10], table[] = {2, 7, 9};
    x_arr(size_ma, multi_arr, table); // F15

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Create a 3-D array and print the address of its elements in the increasing order */
    int TD_arr[2][3][4];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                printf("The address at index number %d%d%d is %u\n", i, j, k, &TD_arr[i][j][k]);
            }
        }
    }

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // STRINGS:
    /* A string is a 1-D character array terminated by a null character ('\0')
       A null character is used to denote the termination of a string. Characters are stored in contiguous memory locations.
       ex: char s[] = {'K', 'E', 'S', 'H', 'A', 'V', '\0};
            OR
           char s[]= "KESHAV";  // In this case, C adds a null character automatically
    */

    char s[] = "KESHAV";
    printf("%s\n", s);

    /* To ask an input string from user:
    scanf("%s", s);    // There's no need to use '&' operator to ask the string type input from user. */

    // GETS() and PUTS()

    /* gets() is a function which can be used to receive a multi-word string.
    gets(s);    // The entered string is stored in s[]  */

    /* puts() can be used to output a string. */
    puts(s); // Prints the string and places the cursor on the next line

    // NOTE: Use 'fgets' instead of 'gets' beacuse:
    /* 1. gets() causes Buffer Overflow
       2. Deprecated from the C11 library due to safety issues.
    */

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // DECLARING A STRING USING POINTERS (We will use this when we have to change the string continuously in a program)
    // char *ch_ptr = "Keshav"; // This character pointer points to the first character of the string
    /* This tells the compiler to store the string in memory and assigned address is stored in a char pointer.
    NOTE:
        1. Once a string is defined using char str[] = "Keshav" , it cannot be reinitialized to something else.
        2. A string defined using pointers can be reinitialized.
    */

    // STANDARD LIBRARY FUNCTIONS FOR STRINGS
    /* C provides a set of standard library functions for string manipulation.
    These functions are declared under <string.h> header file.
    SOME of the most commonly used string functions are:
        1. strlen()
        2. strcpy()
        3. strcat()
        4. strcmp()
    */

    // STRLEN()
    /* This function is used to count the number of characters in the string excluding the null ('\0') characters. */
    char str[] = "Keshav";
    int len = strlen(str);
    printf("Your name \"%s\" is %d characters long.", str, strlen(str));

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // STRCPY()
    /* This function is used to copy the content of second string into first string passed to it */
    char str1[30], str2[] = "KESHAV";
    printf("str1 = %s  ,  str2 = %s\n\nAfter copying str2 in str1\n", str1, str2);
    strcpy(str1, str2);
    printf("str1 = %s  ,  str2 = %s\n", str1, str2);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // STRCAT()
    /* This function is used to concatenate (ek saath join karta hai do strings ko) two strings aur concatenated (final string) ko first string mein store karta hai. */
    char string1[] = "KESHAV ", string2[] = "MANDAL";
    strcat(string1, string2);
    printf("%s", string1);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // STRCMP()
    /* This function is used to compare two strings
        It returns = 0, if both the strings are equal
        It returns a negative value if first string's mismatching character's ASCII value is lesser than second string's corresponding mismatching character
        It returns a positive value otherwise
    */
    char scmp1[] = "KESHAV", scmp2[] = "KESHAV", scmp3[] = "MANDAL";
    printf("strcmp( %s , %s ) = %d\n", scmp1, scmp2, strcmp(scmp1, scmp2)); // Will return '0' since both the strings are equal
    printf("strcmp( %s , %s ) = %d\n", scmp1, scmp3, strcmp(scmp1, scmp3)); // Will return '-1' (a negative value) since 75(ASCII value of K) < 77(ASCII value of M)
    printf("strcmp( %s , %s ) = %d\n", scmp3, scmp1, strcmp(scmp3, scmp1)); // Will return '1' (a positive value) since 77(ASCII value of M) < 75(ASCII value of K)

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write your own version of strlen() function from <string.h> */
    char owns[] = "Keshav Mandal";
    printf("Your name \"%s\" contains %d characters", owns, Strlen(owns)); // F16

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write a function Slice() to slice a string. It should change the original string such that it is now the sliced string. Take two integers as the starting and ending position for slice. */
    char slice[] = "ANYWHERE";
    int sStart = 4, sEnd = 8;
    printf("The original string is: %s\n", slice);
    printf("\nSlicing positions:\nStart = %d , End = %d\n", sStart, sEnd);
    Slice(slice, sStart, sEnd); // F17

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write your own version of strcpy() function from <string.h> */
    char cstr1[50] = "ONEPIECE", cstr2[] = "Keshav Mandal";
    printf("str1 = %s  ,  str2 = %s\n\nAfter copying str2 in str1\n", cstr1, cstr2);
    Strcpy(cstr1, cstr2); // F18
    printf("str1 = %s  ,  str2 = %s\n", cstr1, cstr2);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write a program to encrypt a string by adding 1 to the ASCII value of its characters */
    /* Consider that mera ek password hai jo mai nahi chahta ki kissi aur ko pata chale toh mai uss password ko encrypt kar dunga.
    Ex.: Mai uss password ke har ek characters ki ASCII value ko agar 1 se add kar diya toh ab woh pattern bass mujhe hi pata hai.
    Agar koi unauthorised user hai toh usko thodi na pata hai ki maine uss password ko kiss logic ke saath encrypt kiya hai.
    AND THIS IS ALL ABOUT SASTA ENCRYPTION. */

    char org_password[] = "Luffy@1234", org2_pass[100], user_entered[] = "Kaido936";
    strcpy(org2_pass, org_password);
    int pass_count = 0;

    for (int i = 0; org_password[i] != '\0'; i++)
    {
        if (org_password[i] == user_entered[i])
        {
            pass_count++;
        }
        org_password[i] += 1;
    }
    if (pass_count == strlen(org_password))
    {
        printf("Yokoso Keshav-san !");
    }
    else
    {
        printf("Stay away, you thief !");
    }

    /* Maine yeh problem ko main aim se thoda different bana diya hai but it's more fun this way. */

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write a program to decrypt the string encrypted using the same variables from above problem. */
    printf("The original password is: %s and the user-entered password is: %s\nThe encrypted password is: %s\n\n", org2_pass, user_entered, org_password);

    for (int i = 0; org_password[i] != '\0'; i++)
    {
        org_password[i] -= 1;
    }

    printf("The decrypted (original) password is: %s", org_password);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write a program to count the occurence of a given character in a string */
    char o_str[] = "supercalifragilisticexpialidocious", o_check = 'i';
    int o_count = 0;

    for (int i = 0; o_str[i] != '\0'; i++)
    {
        if (o_str[i] == o_check)
        {
            o_count++;
        }
    }
    printf("Character '%c' occured %d times in the string \"%s\"", o_check, o_count, o_str);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write a program to check whether a given character is present in the string or not. */
    char p_str[] = "Triantiwantigongolope", p_char = 'a';
    for (int i = 0; o_str[i] != '\0'; i++)
    {
        if (o_str[i] == o_check)
        {
            o_count++;
        }
    }
    if (o_count > 0)
    {
        printf("Character '%c' is present in the string \"%s\"", p_char, p_str);
    }
    else
    {
        printf("Character '%c' is NOT present in the string \"%s\"", p_char, p_str);
    }

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // STRUCTURES:
    /* Array & strings -> Similar data (int type or float type or char type), koi bhi ek type ka hi data store kar sakte hai
    Structures can hold -> Dissimilar data
    Structure is a user defined data type.
    So, a structure in C is a collection of variable of different types under a single name.*/

    // Declaration of a structure 'student':
    /* Structure declaration is done outside the main function */

    // Use of structure 'student':
    struct Student stud1; // Creating a structure variable     // S1
    strcpy(stud1.name, "Keshav");
    stud1.roll_no = 29;
    stud1.marks = 5.2;

    struct Student stud2; // S1
    strcpy(stud2.name, "Luffy");
    stud2.roll_no = 56;
    stud2.marks = 99.99;

    printf("Student info:\nStudent name: %s\nRoll no: %d\nTotal marks obtained: %.2f\n", stud1.name, stud1.roll_no, stud1.marks);
    printf("\nStudent info:\nStudent name: %s\nRoll no: %d\nTotal marks obtained: %.2f\n", stud2.name, stud2.roll_no, stud2.marks);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // WHY USE STRUCTURES ?
    /* We can create the data types in the Student structure separately but when the number of properties in a structure increases, it becomes difficult for us to create data variables without structures
    In a nutshell:
        a. Structures keep the data organized.
        b. Structures make data management easy for the programmer.
    */

    // ARRAY OF STRUCTURES:
    /* Just like an array of integers, an array of floats and an array of characters, we can create an array of structures. */
    struct Student stud[10];
    char mugiwara_class[10][10] = {"LUFFY", "ZORO", "NAMI", "USSOP", "SANJI", "CHOPPER", "ROBIN", "FRANKY", "BROOK", "JIMBEI"};
    // mugiwara_class[No_of_Names][Name_Length]
    float bounty_marks[] = {3, 1.111, 500, 1.032, 366, 1000, 930, 394, 383, 1.1};

    printf("Students info:\n\n");
    for (int i = 0; i < 10; i++)
    {
        strcpy(stud[i].name, mugiwara_class[i]);
        printf("Name: %s\n", stud[i].name);

        stud[i].roll_no = i + 1;
        printf("Roll no: %d\n", stud[i].roll_no);

        stud[i].marks = bounty_marks[i];
        printf("Marks : %.3f\n\n", stud[i].marks);
    }

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // INITIALIZING STRUCTURES:
    /* Structures can also be initialized as follows: */
    struct Student Student1 = {"Keshav", 28, 67.21};
    struct Student Student2 = {"Zoro", 2, 100};
    struct Student Student3 = {0}; // All elements are set to zero

    printf("Student 1:\nName: %s\nRoll Number: %d\nTotal marks obtained: %.2f\n\n", Student1.name, Student1.roll_no, Student1.marks);
    printf("Student 2:\nName: %s\nRoll Number: %d\nTotal marks obtained: %.2f\n\n", Student2.name, Student2.roll_no, Student2.marks);
    printf("Student 3:\nName: %s\nRoll Number: %d\nTotal marks obtained: %.2f", Student3.name, Student3.roll_no, Student3.marks);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // STRUCTURES IN MEMORY:
    /* Structures are stored in contiguous memory locations.
        For the Structure Student1 of type struct Student, memory layout looks like this: */
    //              ___________________________________
    //             |   "Keshav"   |   28   |   67.21   |
    //             |______________|________|___________|
    // Address --->     78810        78814      78818

    /* In an array of structures, these Student instances are stored adjacent to each other. */

    // POINTER TO STRUCTURES:
    /* A pointer to structure can be created as follows: */
    struct Student *ptr;
    ptr = &Student1;

    /* Now we can print structure elements using: */
    printf("Student 1:\nName: %s\nRoll Number: %d\nTotal marks obtained: %.2f\n\n", (*ptr).name, (*ptr).roll_no, (*ptr).marks);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // ARROW OPERATOR:
    /* Instead of writing *(ptr).name OR *(ptr).roll_no OR *(ptr).marks , we can use arrow operator to access structure properties as follows:
        *(ptr).name can be written as ptr->name
        *(ptr).roll_no can be written as ptr->roll_no
        *(ptr).marks can be written as ptr->marks
       Here -> is known as the arrow operator.
    */
    ptr = &Student2;
    printf("Student 2:\nName: %s\nRoll Number: %d\nTotal marks obtained: %.2f\n\n", ptr->name, ptr->roll_no, ptr->marks);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PASSING STRUCTURE TO A FUNCTION:
    /* A structure can be passed to a function just like any other data type. */
    display_structure(Student1); // F19

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // typedef KEYWORD:
    /* With the help of this keyword, we can define any word as our own data type. */
    typedef int own_data_type; // own_data_type is the user defined data type here which declares and defines the variable of type integer.
    own_data_type variable = 8;
    printf("%d\n\n", variable);

    /* But typedef keyword iss tarah se jyada use nhi hota hai. Uska main use hai structures mein. */
    /* S2 has been defined outside the main function. */
    /* Now, instead of declaring the structures as:
            struct Employee e1;
       We can declare the structures quicker and efficiently as:
            Emp e1;
    */
    Emp e1; // S2
    Emp *e1_ptr = &e1;
    strcpy(e1.name, "Pirate King");
    e1.id_no = 28;
    e1.salary = 99.99;
    // printf("Employee Details:\nName: %s\nID no: %d\nSalary: %f",el.name, el.id_no, e1.salary);
    printf("Employee Details:\nName: %s\nID no: %d\nSalary: %.2f", e1_ptr->name, e1_ptr->id_no, e1_ptr->salary);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Create a two dimensional vector using structures in C */
    vec v = {1, 2}; // S3
    printf("The value of vector = %di + %dj", v.i, v.j);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write a function 'sumVector' which returns the sum of two vectors passed to it. The vectors must be two-dimensional. */
    vec vec1 = {9, 5}, vec2 = {8, 3};
    printf("Vector 1 = %di + %dj", vec1.i, vec1.j);
    printf("\nVector 2 = %di + %dj", vec2.i, vec2.j);
    sumVector(vec1, vec2); // F20

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write a program with a structure representing a complex number. */
    cx com = {7, 1}; // S4
    printf("The complex number = %d + %di", com.real, com.img);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write a structure capable of storing date. Write a function to compare those dates. */
    date d1 = {28, 9, 2024};
    date d2 = {25, 3, 2026};
    printf("After comparing both dates, result = %d\n", CompareDates(d1, d2));

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // FILE I/O
    /* The Random Access Memory is volatile and if its content is once lost, the program terminates. In order to persist the data forever we use files.
        A file is data stored in a storage device.
        A C program can talk to the file by reading content from it and writing content to it.
    */

    // FILE POINTER:
    /* A "FILE" is a structure which needs to be created for opening a file.
        A file pointer is a pointer to this structure of the file.
        (FILE pointer is needed for communication between the file and the program).
    */

    // FILE OPENING MODES IN C:
    /* C offers the programmers to select a mode for opening a file.
       Following modes are primarily used in C File I/O:
         "r" --> open for reading   // If the file does not exist, fopen returns NULL
         "rb" --> open for reading in binary    // If the file does not exist, fopen returns NULL
         "w" --> open for writing    // If the file exists, the contents will be overwritten
         "wb" --> open for writing in binary    // If the file exists, the contents will be overwritten
         "a" --> open for append    // If the file does not exist, it will be created
    */

    // TYPES OF FILES:
    /* There are two types of files:
         1. Text files (.txt, .c)
         2. Binary files (.jpg, .dat)
     */

    // READING A FILE:
    /* A file can be opened for reading as follows: */

    FILE *fptr;
    // Syntax: ptr = fopen("filename.extension", "mode");
    fptr = fopen("keshav.txt", "r");
    int fnum;
    fscanf(fptr, "%d", &fnum); // This function reads the integer value written inside the file at ptr = 0 position
    printf("The value inside the file = %d", fnum);
    fscanf(fptr, "%d", &fnum); // This function reads the integer value written inside the file at ptr = (length of 1st integer) position
    printf("\nThe value inside the file = %d", fnum);
    /* pointer inside the file keeps on incrementing automatically */

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write a program to check whether the file exists or not before opening the file. */
    if (fptr == NULL)
    {
        printf("The file does not exist");
    }
    else
    {
        printf("The file exists");
    }

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // CLOSING THE FILE:
    /* It is very important to close the file after read or write operation. This is achieved using fclose as follows: */
    fclose(fptr);
    /* This will tell the compiler that we are done working with the file and the associated resources could be freed. */

    // WRITING TO A FILE:
    /* We can write to a file in a very similar manner like we read the file. */
    FILE *fptr2;

    //* Warning: write-operation first clears all the previous contents present in the file and then writes into it.
    //* To avoid this, open file in append mode and then the new contents will be written into the end of the file.

    // fptr2 = fopen("keshav.txt", "w");    // write mode
    fptr2 = fopen("keshav.txt", "a"); // append mode
    int fnum2 = 432;
    fprintf(fptr2, "%d", fnum2);
    fclose(fptr2);

    // fgetc() AND fputc()
    /* fgetc and fputc are used to read and write a character from/to a file. */

    /* fgetc(): */
    fopen("keshav.txt", "r");
    char fc = fgetc(fptr2); // used to read a character from file
    printf("%c", fc);
    fclose(fptr2);

    /* fputc(): */
    fopen("keshav.txt", "a");
    fputc('K', fptr2); // used to write a character 'c' to the file
    fclose(fptr2);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // EOF: END OF FILE
    /* fgetc() returns EOF when all the characters from a file have been read. So we can write a check like below to detect end of file */
    FILE *fptr3;
    fptr3 = fopen("keshav.txt", "r");
    char fch;
    while (1) // while, condition is true
    {
        fch = fgetc(fptr3);
        if (fch == EOF)
        {
            break;
        }
        printf("%c", fch);
    }
    fclose(fptr3);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write a program to read three integers from a file. */
    FILE *fptr4;
    fptr4 = fopen("read3int.txt", "r");
    int fno, no1, no2, no3;
    fscanf(fptr4, "%d%d%d", &no1, &no2, &no3);
    printf("%d %d %d", no1, no2, no3);
    fclose(fptr4);

    // printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write a program to generate multiplication table of a given number in text format. Make sure that the file is readable and well formatted. */
    int multi = 6;
    FILE *fptr5;
    fptr5 = fopen("table.txt", "a");
    for (int i = 0; i < 10; i++)
    {
        fprintf(fptr5, "%d x %d = %d%c", multi, i + 1, multi * (i + 1), '\n');
    }
    fclose(fptr5);

    // printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write a program to read a text file character by character and write its content twice in a separate file. */
    FILE *fptr6, *fptr7;
    fptr6 = fopen("readtext.txt", "r");
    fptr7 = fopen("creadtext.txt", "a");
    char fchar;
    while (1)
    {
        fchar = fgetc(fptr6);
        if (fchar == EOF)
        {
            break;
        }
        fprintf(fptr7, "%c", fchar);
    }
    fclose(fptr6);
    fclose(fptr7);

    // printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Write a program to modify a file containing an integer to double its value.
       ex:       2           4
            prev file    new file
    */
    FILE *fptr8;
    fptr8 = fopen("double.txt", "r");
    int getno;
    fscanf(fptr8, "%d", &getno);
    fclose(fptr8);
    fptr8 = fopen("double.txt", "w");
    fprintf(fptr8, "%d", getno * 2);
    fclose(fptr8);

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // DYNAMIC MEMORY ALLOCATION:
    /* C is a language with some fixed rules of programming.
        For example: changing the size of an array is not allowed.
        ex:
            int n;
            scanf("%d", &n);
            int arr[n];     // NOTE: This is not allowed in C because the size of array 'n' will vary as per the input from the user.
        The solution to the above problem is DMA.
    */

    /* Dynamic Memory Allocation is a way to allocate memory to a data structure during the runtime.
        We can use DMA functions available in C to allocate and free memory during runtime.
    */

    // FUNCTIONS FOR DMA IN C:
    /* Following functions are available in C to perform Dynamic Memory Allocation:
        1. malloc()
        2. calloc()
        3. free()
        4. realloc()
    */

    // malloc FUNCTION:
    /* malloc stands for memory allocation. it takes number of bytes to be allocated as an input and returns a pointer of type void
     Syntax: ptr = (int*) malloc(30 * sizeof(int));

         ptr = (int*)             malloc(    30     *      sizeof(int))
                  |                          |                |
                  V                          V                V
               casting void        space for 30 ints     returns size of 1 int
               pointer to int

     The expression returns a null pointer if the memory cannot be allocated.
    NOTE: By default the values will be garbage values.
    */

    // PROBLEM:
    /* Write a program to create a dynamic array of 5 floats using malloc() */
    float ArrSize = 5, *dmaPtr;
    dmaPtr = (float *)malloc(ArrSize * sizeof(float));

    dmaPtr[0] = 3;
    dmaPtr[1] = 4.52;
    dmaPtr[2] = 9.21;
    dmaPtr[3] = 5.08;
    dmaPtr[4] = 6.11;

    for (int i = 0; i < ArrSize; i++)
    {
        printf("%f\n", dmaPtr[i]);
    }

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // calloc() FUNCTION:
    /* calloc stands for continuous allocation.
        calloc aur malloc LAGBHAG same hi hote hai.
    NOTE: It initializes each memory block with a default value of 0
    */

    /* Syntax:
        ptr = (float*) calloc(30, sizeof(float));
        Allocates contiguous space in memory for 30 blocks (floats).
    */

    /* If the space is not sufficient, memory allocation fails and a NULL pointer is returned. */

    // PROBLEM:
    /* Write a program to create a dynamic array of 5 floats using calloc() */
    float ArrSize2 = 5, *dmaPtr2;
    dmaPtr2 = (float *)calloc(ArrSize2, sizeof(float));

    dmaPtr2[0] = 3;
    dmaPtr2[1] = 4.52;
    dmaPtr2[2] = 9.21;
    dmaPtr2[3] = 5.08;
    dmaPtr2[4] = 6.11;

    for (int i = 0; i < ArrSize2; i++)
    {
        printf("%f\n", dmaPtr2[i]);
    }

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // free() FUNCTION:
    /* We can use free() function to deallocate the memory.
    The memory allocated using calloc/malloc is not deallocated automatically. */

    /* Synatx:
                free(ptr);
        Memory of ptr is released.
    */

    /* It is always a good practice to free the allocated memory after the desired output */

    // PROBLEM:
    /* Write a program to demonstrate the usage of free() with malloc() */
    float ArrSize3 = 5, *dmaPtr3;
    dmaPtr3 = (float *)malloc(ArrSize3 * sizeof(float));

    dmaPtr3[0] = 3;
    dmaPtr3[1] = 4.52;
    dmaPtr3[2] = 9.21;
    dmaPtr3[3] = 5.08;
    dmaPtr3[4] = 6.11;

    printf("Before releasing the memory:\n");
    for (int i = 0; i < ArrSize3; i++)
    {
        printf("%f\n", dmaPtr3[i]);
    }

    free(dmaPtr3); // Memory of dmaPtr3 is released. We won't know this in our computer architechture but the memory is freed.

    printf("\nAfter releasing the memory:\n");
    for (int i = 0; i < ArrSize3; i++)
    {
        printf("%f\n", dmaPtr3[i]); // It will throw garbage value because its malloc() function.
    }

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // realloc() FUNCTION:
    /* Sometimes the dynamically allocated memory is insufficient or more than required.
    realloc is used to allocate memory of new size using the previous pointer and size. */

    /* Syntax:
    ptr = realloc(ptr, newSize);
    ptr = realloc(ptr, 3 * sizeof(int));
    ptr now points to this new block of memory capable of storing 3 integers.
    */

    /* Pahile agar tumne 5 variable store karne ka pointer banaya tha malloc() ke through aur ab chahte ho ki woh ptr 10 data store kare tab realloc kaam aata hai. */

    /* Example: */
    float ArrSize4 = 5, *dmaPtr4;
    dmaPtr4 = (float *)malloc(ArrSize4 * sizeof(float));

    dmaPtr4[0] = 1;
    dmaPtr4[1] = 2;
    dmaPtr4[2] = 3;
    dmaPtr4[3] = 4;
    dmaPtr4[4] = 5;

    for (int i = 0; i < ArrSize4; i++)
    {
        printf("%.0f\n", dmaPtr4[i]);
    }

    dmaPtr4 = (float *)realloc(dmaPtr4, 10 * sizeof(float));

    printf("\nAfter reallocating array size 5 to 10:\n");

    dmaPtr4[0] = 1;
    dmaPtr4[1] = 2;
    dmaPtr4[2] = 3;
    dmaPtr4[3] = 4;
    dmaPtr4[4] = 5;
    dmaPtr4[5] = 6;
    dmaPtr4[6] = 7;
    dmaPtr4[7] = 8;
    dmaPtr4[8] = 9;
    dmaPtr4[9] = 10;

    for (int i = 0; i < 10; i++)
    {
        printf("%.0f\n", dmaPtr4[i]);
    }

    printf("\n\n------------------------------------------------------------------------------------\n\n");

    // PROBLEM:
    /* Create an array of multiplication table of 7 upto (7x10=70). Use realloc to make it store 15 numbers (from 7x1 to 7x15). */
    int *dyMulArr;
    dyMulArr = (int *)malloc(10 * sizeof(int));

    printf("Multiplication table of 7 upto 10:\n");
    for (int i = 0; i < 10; i++)
    {
        dyMulArr[i] = 7 * (i + 1);
        printf("7 x %d = %d\n", i + 1, dyMulArr[i]);
    }

    dyMulArr = (int *)realloc(dyMulArr, 15 * sizeof(int));

    printf("\nMultiplication table of 7 upto 15:\n");
    for (int i = 0; i < 15; i++)
    {
        dyMulArr[i] = 7 * (i + 1);
        printf("7 x %d = %d\n", i + 1, dyMulArr[i]);
    }

    return 0; // returns a value to main() function.
}