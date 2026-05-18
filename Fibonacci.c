// Program to print the fibonacci series upto a significant terms.
// TriTea@blackpharaoh

#include <stdio.h>
int fibonacci(int n)
{
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    printf("Enter the number of terms:");
    int num;
    scanf("%d", &num);
    if (num <= 0)
    {
        printf("Invalid Input!");
        return 0;
    }
    printf("The series upto %d terms are", num);
    for (int i = 0; i < num; i++)
    {
        printf("%d ", fibonacci(i));
    }
    return 0;
}