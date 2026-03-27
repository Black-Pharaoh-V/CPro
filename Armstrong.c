#include <stdio.h>
// Program to verify Armstrong number and also print Armstrong numbers in a given range.
// TriTea@BlackPharaoh

int main()
{
    int ch;
    do
    {
        printf("Enter your choice:\n1. Verify Armstrong number\n2. Print Armstrong number in a given range:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("Enter a number to verify:\n");
            int num;
            scanf("%d", &num);
            int sum = 0, temp, r;
            temp = num;
            while (temp != 0) // Logic to check for Armstrong Number.
            {
                r = temp % 10;    // Take the last number
                sum += r * r * r; // Multiply to find cube and sum them up
                temp = temp / 10;
            }
            if (sum == num) // Check the equality.
                printf("%d is an Armstrong Number\n", num);
            else
                printf("%d is not an Armstrong Number\n", num);
            break;
        }
        case 2:
        {
            printf("Enter the range to find the number:\n");
            int f, l;
            scanf("%d %d", &f, &l);
            int i, sum = 0, temp, r;
            if (f > l)
            {
                printf("Range is invalid!\n"); // TO CHECK FOR THE CORRECT RANGE LIMIT.
                break;
            }
            for (i = f; i <= l; i++)
            {
                sum = 0; // To reset the sum value after each iteration.
                temp = i;
                while (temp != 0) // Logic loop to check for Armstrong Number.
                {
                    r = temp % 10;    // Take the last number
                    sum += r * r * r; // Multiply to find cube and sum them up
                    temp = temp / 10;
                }
                if (sum == i)
                {
                    printf("%d ", i);
                }
            }
            printf("\n");
            break;
        }
        default:
        {
            printf("Invalid Input!\n");
        }
        }
        printf("Enter 1 to continue or press any key to exit!\n");
        scanf("%d", &ch);
    } while (ch == 1);

    return 0;
}