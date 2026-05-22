// Program to print Boundary and Non-Boundary elements in a Matrix.
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

void Boundary(int M[Max][Max], int r, int c)
{
    printf("\nBoundary Elements:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 0 || i == r - 1 || j == 0 || j == c - 1) // Check for Boundary elements.
                printf("%d ", *(*(M + i) + j));
            else
                printf(" "); // Leave empty space for inner elements
        }
        printf("\n");
    }
}

void Non_Boundary(int M[Max][Max], int r, int c)
{
    printf("Non-Boundary Element:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i != 0 && i != r - 1 && j != 0 && j != c - 1)
                printf("%d ", *(*(M + i) + j));
            else
                printf(" "); // leave space for boundary elements.
        }
        printf("\n");
    }
}

int main()
{
    int A[Max][Max];
    int r = 0, c = 0;
    input(A, &r, &c);
    Print(A, r, c);
    Boundary(A, r, c);
    Non_Boundary(A, r, c);

    return 0;
}