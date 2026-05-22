// Program to find the majority number in an array.
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
        printf("Elements %d", i + 1);
        scanf("%d", &arr[i]);
    }

    // Using selection sorting.
    for (int i = 0; i < n - 1; i++)
    {
        int md = i;
        for (int j = i + 1; j < n; j++)
        {
            if (*(arr + j) < *(arr + md))
                md = j;
        }
        int temp = *(arr + md);
        *(arr + md) = *(arr + i);
        *(arr + i) = temp;
    }

    int cd = *(arr + (n / 2));
    int low, high, mid;
    int f = -1, l = -1;

    // Using Binary searching ,method.
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (*(arr + mid) == cd)
        {
            f = mid;
            high = mid - 1;
        }
        else if (*(arr + mid) > cd)
            high = mid - 1;
        else
            low = mid + 1;
    }

    low = 0;
    high = n - 1; // Resetting the values
    // Binary Search for last occurrence.
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (*(arr + mid) == cd)
        {
            l = mid;
            high = mid - 1;
        }
        else if (*(arr + mid) > cd)
            high = mid - 1;
        else
            low = mid + 1;
    }

    int ct = l - f + 1;
    if (ct > n / 2)
        printf("\nThe majority element is: %d (appears %d times)\n", cd, ct);
    else
        printf("\nThere is no majority element in this array.\n");

    return 0;
}