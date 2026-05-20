// Program to find the Majority Number in an array using Selection Sorting and Binary Searching.
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

    // Applying Selection Sorting.
    for (int i = 0; i < n; i++)
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
    int low = 0, high = n - 1, mid;
    int f = -1, l = -1;

    // Applying Binary Search for first occurrence.
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (*(arr + mid) == cd)
        {
            f = mid;
            high = mid - 1;
        }
        else if (*(arr + mid) > cd)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    low = 0;
    high = n - 1; // Resetting the values.
    // Binary search for Last occurrence.
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (*(arr + mid) == cd)
        {
            l = mid;
            low = mid + 1;
        }
        else if (*(arr + mid) > cd)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    int ct = l - f + 1;
    if (ct > n / 2)
    {
        printf("\n The Majority element found is: %d (appears %d times)\n", cd, ct);
    }
    else
    {
        printf("There is no majority element.");
    }
    return 0;
}