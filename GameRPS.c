// Program to design the Rock-Paper-Scissors Game.
// TriTea@blackpharaoh

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char moves[3][10] = {"Rock", "Paper", "Scissors"};
    int pchoice, cchoice;

    srand(time(NULL));

    printf("\n --- Rock-Paper-Scissors Game --- \n");
    printf("0. Rock\n");
    printf("1. Paper\n");
    printf("2. Scissors\n");
    printf("Enter your choice: \n");
    scanf("%d", &pchoice);

    if (pchoice < 0 || cchoice > 2)
    {
        printf("Invalid choice! Try again\n");
        return 1;
    }

    cchoice = rand() % 3;

    printf("\n You chose: %s\n", moves[pchoice]);
    printf("\n Computer chose: %s\n", moves[cchoice]);

    if ((pchoice == cchoice))
    {
        printf("\n It's a TIE\n");
    }
    else if ((pchoice == 0 && cchoice == 2) || (pchoice == 1 && cchoice == 0) || (pchoice == 2 && cchoice == 1))
        printf("\n Congratulations! You win\n");
    else
        printf("\n Computer wins! Better luck next time.\n");
    return 0;
}