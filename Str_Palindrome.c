// Program to search and Print the Palindrome word from a character matrix.
// TriTea@blackpharaoh

#include <stdio.h>
#include <string.h>
#define Max 50

void Palindrome(char g[Max][Max], int r, int c, char t[])
{
    int len = strlen(t);
    int fd = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            // Horizontal search.
            if (j + len <= c)
            {
                int match = 1;
                for (int k = 0; k < len; k++)
                {
                    if (g[i][j + k] != t[k])
                    {
                        match = 0;
                        break;
                    }
                }
                if (match)
                {
                    printf("Found Palindrome '%s' horizontally in Row %d", t, i + 1);
                    fd = 1;
                }
            }

            // Vertical Search.
            if (i + len <= r)
            {
                int match = 1;
                for (int k = 0; k < len; k++)
                {
                    if (g[i + k][j] != t[k])
                    {
                        match = 0;
                        break;
                    }
                }
                if (match)
                {
                    printf("Found Palindrome '%s' vertically in Column %d", t, j + 1);
                    fd = 1;
                }
            }
        }
    }
    if (!fd)
    {
        printf("Palindrome word '%s' not found.\n", t);
    }
}

int main()
{
    char A[Max][Max];
    char t[50];
    int r, c;
    printf("Enter rows and columns:\n");
    scanf("%d %d", &r, &c);

    printf("Enter characters row by row:\n");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("A[%d][%d]:", i, j);
            scanf("%c", &A[i][j]);
        }
    }
    printf("\n Enter the Palindrome word to look for:-");
    scanf("%s", &t);

    printf("\n -- Search Results--\n");
    Palindrome(A, r, c, t);
    return 0;
}