// Snake Water Gun Game
/*
Snake Water Gun is a game most of us have played during school time.
Write a C program capable of playing this game with you.
Your program should be able to print the result after you choose Snake / Water / Gun.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
loop:
    srand(time(0));
    int player, computer = rand() % 3;
    /*
        0 --> Snake
        1 --> Water
        2 --> Gun
    */

    printf("Choose 0 for Snake, 1 for Water, 2 for Gun\n");
    scanf("%d", &player);
    printf("Computer chose %d\n", computer);

    if ((player == 0 && computer == 0) || (player == 1 && computer == 1) || (player == 2 && computer == 2))
    {
        printf("It's a Draw!\n");
    }
    else if ((player == 0 && computer == 1) || (player == 1 && computer == 2) || (player == 2 && computer == 0))
    {
        printf("You Won!\n");
    }
    else if ((player == 0 && computer == 2) || (player == 1 && computer == 0) || (player == 2 && computer == 1))
    {
        printf("You Lose!\n");
    }
    else
    {
        printf("Something went wrong!\n");
    }
    goto loop;
    return 0;
}