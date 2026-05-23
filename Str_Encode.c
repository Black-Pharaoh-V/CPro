// Program to print the String in Run-Length Encode form.
// TriTea@blackpharaoh

#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    printf("Enter the string please:-\n");
    scanf("%s", str);

    int len = strlen(str);
    int ct = 1;

    printf("Encoded String:-\n");
    for (int i = 0; i < len; i++)
    {
        // if next char is same increase count.
        if (i + 1 < len && str[i] == str[i + 1])
        {
            ct++;
        }
        else
        {
            printf("%c%d", str[i], ct);
            ct = 1; // Reset count.
        }
    }
    printf("\n");

    return 0;
}