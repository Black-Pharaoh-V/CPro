#include <stdio.h>
#include <math.h>
//Program to check if a number is an Armstrong number and to print all Armstrong numbers in a given range.
//TriTea@blackpharaoh

// Function to count digits in a number
int countDigits(int n) {
    int count = 0;
    if (n == 0) return 1;
    while (n != 0) {
        n /= 10;
        count++;
    }
    return count;
}

// Function to check if a number is an Armstrong number
int isArmstrong(int n) {
    int sum = 0, temp = n, r;
    int digits = countDigits(n);
    
    while (temp != 0) {
        r = temp % 10;
        // Use pow() for dynamic digit support. 
        // We add 0.5 before casting to int to avoid floating point precision errors.
        sum += (int)(pow(r, digits) + 0.5);
        temp /= 10;
    }
    return (sum == n);
}

int main() {
    int ch;
    do {
        printf("\nEnter your choice:\n1. Verify Armstrong number\n2. Print Armstrong numbers in a range\n3. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: {
                printf("Enter a number to verify: ");
                int num;
                scanf("%d", &num);
                
                if (isArmstrong(num))
                    printf("%d is an Armstrong Number\n", num);
                else
                    printf("%d is not an Armstrong Number\n", num);
                break;
            }
            case 2: {
                int f, l;
                printf("Enter the range (From To): ");
                scanf("%d %d", &f, &l);
                
                if (f > l) {
                    printf("Range is invalid!\n");
                } else {
                    printf("Armstrong numbers: ");
                    for (int i = f; i <= l; i++) {
                        if (isArmstrong(i)) {
                            printf("%d ", i);
                        }
                    }
                    printf("\n");
                }
                break;
            }
            case 3:
                return 0;
            default:
                printf("Invalid Input!\n");
        }

        printf("\nEnter 1 to continue or any other key to exit: ");
        scanf("%d", &ch);
    } while (ch == 1);

    return 0;
}