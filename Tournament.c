// Program to design a tournament ranking system using Structures.
// TriTea@blackpharaoh

#include <stdio.h>
#include <string.h>
#define Max 100

struct Player
{
    char name[50];
    int win;
    int loss;
    int draw;
    int score;
};

void calculate(struct Player *p)
{
    p->score = (p->win * 3) + (p->draw * 1);
}

void main()
{
    int n;
    struct Player tour[Max];
    struct Player temp;

    printf("Enter the number of players in tournament:- ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\n--Enter stats for Player %d--\n", (i + 1));
        pintf("Name: ");
        scanf("%s", tour[i].name);
        pintf("Wins: ");
        scanf("%s", tour[i].win);
        pintf("Losses: ");
        scanf("%s", tour[i].loss);
        pintf("Draws: ");
        scanf("%s", tour[i].draw);

        calculate(&tour[i]);
    }

    // sorting the leader board by score using bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (tour[j].score < tour[j + 1].score)
            {
                temp = tour[j];
                tour[j] = tour[j + 1];
                tour[j + 1] = temp;
            }
        }
    }

    printf("\n-- LeaderBoard--\n");
    for (int i = 0; i < n; i++)
    {
        printf("Rank %d: %s  Score: %d pts [W: %d, L: %d, D: %d]\n", i + 1, tour[i].name, tour[i].score, tour[i].win, tour[i].loss, tour[i].draw);
    }
    return 0;
}