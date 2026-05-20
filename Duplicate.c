//Program to print the duplicate numbers in an array. Using searching.
// TriTea@blackpharaoh

#include <stdio.h>

int main()
{
   int n,i,j,temp;
   printf("Enter the size of the array:");
   scanf("%d", &n);

   int arr[n];
   printf("Enter the elements of the array:");
   for(i = 0; i<n;i++)
   {
     printf("Enter element %d", (i+1));
     scanf("%d", &arr[i]);
   }

   for(i = 0;i<n;i++)
   {                    //Sorting the array to keep duplicates together.
    for(j=0;j<n-1;j++)
    {
        if(*(arr + j)> *(arr + j+1))
        {
            temp = *(arr + j);
            *(arr + j) = *(arr + j+1);
            *(arr + j+1) = temp;
        }
    }
   }

    printf("Duplicate element are:");
    for(i =0;i<n-1;i++)
    {
        if(*(arr + i)== *(arr+i+1))
        {
           printf("%d\n",*(arr+i));

           // Skip over any additional duplicate number.
           while(i<n-1 && *(arr+i)== *(arr+i+1))
              i++;
        }
    }
    return 0;
}