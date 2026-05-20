// Program to calculate three sum problem in a single dimension array.
// TriTea@blackpharaoh

#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of array:");
    for (int i = 0; i < n; i++)
    {
        printf("Element %d", i + 1);
        scanf("%d", &arr[i]);
    }

    // Using Selection Sorting.
    for (int i = 0; i < n - 1; i++)
    {
        int md = i;
        for (int j = i + 1; j < n; j++)
        {
            if (*(arr + j) < *(arr + md))
            {
                md = j;
            }
        }
        int temp = *(arr + md);
        *(arr + md) = *(arr + i);
        *(arr + i) = temp;
    }

    printf("\nTriplets that sum to 0 are:\n");
    int fd = 0;

    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && *(arr + i) == *(arr + i - 1))
        {
            continue;
        }
        int left = i + 1;
        int right = n - 1;
        while (left < right)
        {
            int sum = *(arr + i) + *(arr + left) + *(arr + right);
            if (sum == 0)
            {
                printf("[%d, %d, %d]\n", *(arr + i), *(arr + left), *(arr + right));
                fd = 1;

                // Move pointers and skip duplicates.
                while (left < right && *(arr + left) == *(arr + left + 1))
                    left++;
                while (left < right && *(arr + right) == *(arr + right + 1))
                    right--;

                left++;
                right--;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    if (!fd)
    {
        printf("No Triplet found that sum up to 0.\n");
    }
}