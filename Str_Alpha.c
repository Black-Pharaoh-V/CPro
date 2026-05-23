// Program to sort a String Array in alphabetical order.
// TriTea@blackpharaoh

#include <stdio.h>
#include <string.h>

int main()
{
    char A[50][50]; // Array of up to 50 words and 50 characters.
    printf("How many words do you want to enter:\n");
    int n;
    scanf("%d", &n);

    printf("Enter %d words\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("Word %d: ", i + 1);
        scanf("%s", A[i]);
    }
    char temp[50];
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (strcmp(A[j], A[j + 1] > 0))
            {
                strcpy(temp, A[j]);
                strcpy(A[j], A[j + 1]);
                strcpy(A[j + 1], temp);
            }
        }
    }
    printf("\n Sorted Strings are:\n");
    for (int i = 0; i < n; i++)
        printf("%s", A[i]);
    printf("\n");

    return 0;
}