// Program to multiply two matrices in a 2d Array form.
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

void Multiply(int A[Max][Max], int r1, int c1, int B[Max][Max], int c2, int C[Max][Max])
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            *(*(C + i) + j) = 0; // Pointer arithmetic
            for (int k = 0; k < c1; k++)
            {
                *(*(C + i) + j) += (*(*(A + i) + k)) * (*(*(B + k) + j));
            }
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

int main()
{
    int A[Max][Max];
    int B[Max][Max];
    int C[Max][Max];
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
    input(A, &r1, &c1);
    input(B, &r2, &c2);

    if (c1 != r2)
    {
        printf("\n Error! Multiplication Impossible.\n Column1 must be equal to row2 \n");
        return 1;
    }
    Print(A, r1, c1);
    Print(B, r1, c1);
    Multiply(A, r1, c1, B, c2, C);
    Print(C, r1, c2);

    return 0;
}