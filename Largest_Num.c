// Program to find the K-th Largest Number in a single dimension array.
// TriTea@blackpharaoh

#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d", &n);

    int arr[n]; 
    printf("Enter the elements of array:");
    for(int i=0; i<n;i++)
    {
        printf("Element %d", i+1);
        scanf("%d", &arr[i]);
    }
    int k; //To get the k-th largest number.
    printf("Enter the k-th largest number you want to search for:\n");
    scanf("%d", &k);

    //we will sort the loop for easily finding the number.
    for(int i = 0; i<n;i++)
    {
        for(int j=0;j<n-1;j++) 
        {
          if(*(arr + j) > *(arr + j + 1)) //Using pointers to check and sort.
          {
            int temp = *(arr+j);
            *(arr+j) = *(arr+j+1);
            *(arr+j+1) = temp;
          }
        }
    }

    printf("The %d largest number is: %d\n", k, *(arr+n-k)); //Since the sorting happened in ascending order.
    return 0;
}
