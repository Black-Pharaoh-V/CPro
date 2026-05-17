// Program to convert an integer to binary and vice versa.
// TriTea@black_pharaoh

#include <stdio.h>
static int tobinary(int num)
{
    int rem;
    long long binary = 0, place = 1;
    while (num > 0)
    {
        rem = num % 2;         // get remainder 0 or 1
        binary += rem * place; // build the binary equivalent
        place *= 10;           // move to the next place value
        num /= 2;
    }

    return binary;
}

static int todecimal(long long binary)
{
    int decimal = 0, place = 1, rem;
    while (binary > 0)
    {
        rem = binary % 10;      // get the last digit (0 or 1)
        decimal += rem * place; // build the decimal equivalent
        place *= 2;             // move to the next power of 2
        binary /= 10;           // remove the last digit
    }

    return decimal;
}

int main()
{
    int choice;
    do
    {
        printf("1. Convert Integer to Binary\n2. COnvert Binary to Integer\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            int num;
            printf("Enter an integer:\n");
            scanf("%d", &num);
            printf("Binary equivalent: %lld\n", tobinary(num));
            break;
        }
        case 2:
        {
            long long binary;
            printf("Enter a binary number:\n");
            scanf("%lld", &binary);
            printf("Decimal Equivalent: %d\n", todecimal(binary));
            break;
        }
        }
        printf("Do you want to continue? (1 for yes, 0 for no):\n");
        scanf("%d", &choice);
    } while (choice == 1);
}