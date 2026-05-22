// Program to rotate matirces in different degrees.
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

// Right rotation 90 degree (first transpose then reverse)
void rotate_r90(int A[Max][Max], int r, int c, int B[Max][Max], int *nr, int *nc)
{
    *nr = c;
    *nc = r;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            *(*(B + j) + (r - 1 - i)) = *((*A + i) + j);
        }
    }
}

// Right rotation 180 (Reverse rows and columns)
void rotate_r180(int A[Max][Max], int r, int c, int B[Max][Max], int *nr, int *nc)
{
    *nr = r;
    *nc = c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            *(*(B + (r - 1 - i)) + (c - 1 - j)) = *(*(A + i) + j);
        }
    }
}

// Left rotation 90 (Transpose then reverse columns)
void rotate_r270(int A[Max][Max], int r, int c, int B[Max][Max], int *nr, int *nc)
{
    *nr = c;
    *nc = r;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            *(*(B + (c - 1 - j)) + i) = *(*(A + i) + j);
        }
    }
}

int main()
{
    int A[Max][Max], R[Max][Max];
    int r = 0, c = 0, nr = 0, nc = 0;
    int choice;

    input(A, &r, &c);

    printf("\n ---Matrix Rotation Possible in following ways---\n");
    printf("1. Rotate Left 90 degrees.\n");
    printf("2. Rotate Left 180 degrees.\n");
    printf("3. Rotate Left 270 degrees.\n");
    printf("4. Rotate Right 90 degrees.\n");
    printf("5. Rotate Right 180 degrees.\n");
    printf("6. Rotate Right 270 degrees.\n");
    printf("Enter your choice:\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    {
        rotate_r270(A, r, c, R, &nr, &nc);
        break;
    }
    case 2:
    {
        rotate_r180(A, r, c, R, &nr, &nc);
        break;
    }
    case 3:
    {
        rotate_r90(A, r, c, R, &nr, &nc);
        break;
    }
    case 4:
    {
        rotate_r90(A, r, c, R, &nr, &nc);
        break;
    }
    case 5:
    {
        rotate_r180(A, r, c, R, &nr, &nc);
        break;
    }
    case 6:
    {
        rotate_r270(A, r, c, R, &nr, &nc);
        break;
    }
    default:
    {
        printf("Invalid Input!\n");
        return 1;
    }
    }

    printf("\n Original Matrix:\n");
    Print(A, r, c);

    printf("\n Rotated Matrix:\n");
    Print(R, nr, nc);
}