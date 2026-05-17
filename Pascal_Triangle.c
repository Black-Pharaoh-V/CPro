// Program to print Pascal's Triangle
// TriTea@blackpharaoh

#include <stdio.h>
void Pascal(int n){
    for(int i =0; i<n; i++)
    {
        for(int s=0; s<(n-i)*2; s++)
        {
            printf(" ");
        }
        int value = 1;
        for(int j=0; j<=i; j++)
        {
            printf("%4d", value);
            value = value * (i-j) / (j+1);
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of lines for Pascal's Triangle: ");
    scanf("%d", &n);
    Pascal(n);
    return 0;
}
