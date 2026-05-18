// Program to find the factorial of a number using recursion and also printing factorial in a range.
// TriTea@blackpharaoh

#include <stdio.h>

int factorial(int n)
{
    if (n==0)
        return 1;
    else
        return n*factorial(n-1);
}

int RangeFactorial(int f, int l)
{
    for(int i=f; i<=l; i++)
        printf("Factorial of %d is %d\n", i, factorial(i));
}

int main()
{
    int choice;
    do{
        printf("1. Find factorial of a number\n2. Find the factorial in a range\nEnter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            {
                int n;
                printf("Enter a number:\n");
                scanf("%d", &n);
                printf("Factorial of %d is %d\n", n, factorial(n));
                break;
            }
            case 2:
            {
                int f, l;
                printf("Enter the range (first and last number):\n");
                scanf("%d %d", &f, &l);
                if(f > l)
                   printf("Invalid range! please try again");
                else
                   RangeFactorial(f, l);
                break;
            }
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
        printf("Press 1 to continue or 0 to exit: \n");
        scanf("%d", &choice);
    } while (choice == 1);
}