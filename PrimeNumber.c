// Program to check whether a number is Prime or not, and also print the prime number in a given range.
// TriTea@blackpharaoh

#include <stdio.h>
#include <math.h>

int isPrime(int n) // Function to check if a number is prime or not.
{
    if (n <= 1)
        return 0;
    else
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
                return 0;
        }
        return 1;
    }
}

int RangePrime(int f, int l) // Function to print prime numbers in a given range
{
    for (int i = f; i <= l; i++)
    {
        if (isPrime(i))
            printf("%d ", i);
    }
}

int main()
{
    int choice; // Variable to store user's choice
    do
    {
        printf("1. Check whether a number is Prime or not.\n 2. Print the prime number in a given range. \n Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int num;
            printf("Enter a number to check:");
            scanf("%d", &num);
            if (isPrime(num))
            {
                printf("%d is a prime number \n", num);
            }
            else
                printf("%d is not a prime number \n", num);
            break;
        }
        case 2:
        {
            int f, l;
            printf("Enter the range (From To): ");
            scanf("%d %d", &f, &l);
            printf("Prime numbers in the range %d to %d are: ", f, l);
            RangePrime(f, l);
            break;
        }
        default:
            printf("Invalid choice! Please enter 1 or 2.\n");
        }
        printf("Enter 1 to continue or 0 to exit: ");
        scanf("%d", &choice);
    } while (choice == 1);
    return 0;
}