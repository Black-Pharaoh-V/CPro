// Program to print the spiral of a matrix clockwise and anti-clockwise.
// TriTea@blackpharaoh

#include <stdio.h>
#define Max 50
void input(int M[Max][Max], int *r, int *c)
{
    printf("Enter Rows and columns of the matrix:\n");
    scanf("%d %d", r, c);
    printf("Enter elements for Matrix: M(%dx%d)", r, c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("M[%d][%d]", i, j);
            scanf("%d", &M[i][j]);
        }
    }
}

void Print(int C[Max][Max], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}

void spiral_clock(int A[Max][Max], int r, int c)
{
    int tp=0, bm= r-1, lt=0, rt = c-1;
    printf("\nClockwise Spiral is:\n");
    
    while(tp <= bm && lt<=rt)
    {
        //Print top row.
        for(int i= lt; i<= rt; i++)
           printf("%d", *(*(A+tp)+i));
        tp++;

        //Print right column
        for(int i=tp; i<=bm; i++)
           printf("%d", *(*(A+i)+rt));
        rt--;

        //Print bottom row
        if(tp <= bm)
        {
            for(int i=bm;i>=lt;i--)
               printf("%d", *(*(A+bm)+i));
            bm--;
        }

        //Print left column
        if(lt<=rt)
        {
            for(int i=bm;i>= tp;i--)
               printf("%d", *(*(A+i)+lt));
            lt++;
        }
    }
    printf("\n");
}

void spiral_anticlock(int A[Max][Max], int r, int c)
{
    int tp=0, bm= r-1, lt=0, rt = c-1;
    printf("\nAnti-Clockwise Spiral is:\n");
    
    while(tp <= bm && lt<=rt)
    {
        //Print top row.
        for(int i= rt; i>= lt; i--)
           printf("%d", *(*(A+tp)+i));
        tp++;

        //Print left column
        for(int i=tp; i<=bm; i++)
           printf("%d", *(*(A+i)+lt));
        lt++;

        //Print bottom row
        if(tp <= bm)
        {
            for(int i=lt;i<=rt;i++)
               printf("%d", *(*(A+bm)+i));
            bm--;
        }

        //Print right column
        if(lt<=rt)
        {
            for(int i=bm;i>= tp;i--)
               printf("%d", *(*(A+i)+rt));
            rt--;
        }
    }
    printf("\n");
}

int main()
{
    int A[Max][Max];
    int r=0,c=0;
    int choice;

    input(A, &r, &c);
    Print(A, r, c);

    printf("Spiral Traversal Menu:-\n");
    printf("1.Clockwise Spiral\n");
    printf("2.Anti-Clockwise Spiral\n");
    printf("Enter choice:-\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
        {
            spiral_clock(A, r, c);
            break;
        }
        case 2:
        {
            spiral_anticlock(A, r, c);
            break;
        }
        default:
        {
            printf("\nInvalid Input!\n");
            return 1;
        }
    }

    return 0;
}