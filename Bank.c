// Program to create a bank account using structures.
// TriTea@blackpharaoh

#include <stdio.h>
#define Max 100

struct Bank
{
    int accNum;
    char own;
    double bal;
};

void display(struct Bank acc)
{
    printf("Acc No.: %d\t Name: %s \t Balance: $%.2f\t Status: ", acc.accNum, acc.own, acc.bal);

    // Determine status
    if (acc.bal >= 500.0)
    {
        printf("Minimum Balance Maintained.\n");
    }
    else
    {
        printf("Low Balance\n");
    }
}

int main()
{
    int n;
    struct Bank a[Max];

    printf("How many bank accounts you want to create:\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\n --Enter Details of person %d --", (i + 1));
        printf("Enter account Number:\n");
        scanf("%d", &a[i].accNum);

        printf("Enter account holder name:");
        scanf("%s", a[i].own);

        printf("Enter Balance:");
        scanf("%lf", &a[i].bal);
    }

    printf("\n---ALL ACCOUNT DETAILS ARE---\n");
    for (int i = 0; i < n; i++)
    {
        display(a[i]);
    }
    return 0;
}