// Program to check whether two strings are anagram or not.
// TriTea@blackpharaoh

#include <stdio.h>
#include <string.h>

int anagram(char s1[], char s2[])
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // If length of both words are not equal, then cannot be anagram
    if (len1 != len2)
    {
        printf("\n The Strings are not anagram.\n");
        return;
    }

    // Sort both strings to check for.
    for (int i = 0; i < len1 - 1; i++)
    {
        for (int j = 0; j < len1 - 1; j++)
        {
            if (s1[j] > s1[j + 1])
            {
                char temp = s1[j];
                s1[j] = s1[j + 1];
                s1[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < len2 - 1; i++)
    {
        for (int j = 0; j < len2 - 1; j++)
        {
            if (s2[j] > s2[j + 1])
            {
                char temp = s2[j];
                s2[j] = s2[j + 1];
                s2[j + 1] = temp;
            }
        }
    }

    // Compare the sorted strings.
    for (int i = 0; i < len1; i++)
    {
        if (s1[i] != s2[i])
        {
            printf("\n The Strings are not Anagram\n");
            return;
        }
    }

    printf("The strings are ANAGRAM.\n");
}

int main()
{
    char str1[100];
    char str2[100];

    printf("Enter first string: ");
    scanf("%s", &str1);

    printf("Enter second string: ");
    scanf("%s", &str2);

    anagram(str1, str2);
    return 0;
}