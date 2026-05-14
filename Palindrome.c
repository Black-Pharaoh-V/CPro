//Program to check whether the given number is a palindrome or not, and also print the number in a given range.
//TriTea@blackpharaoh

#include <stdio.h>
 int isPalindrome(int num)  //Funtion to check whether the number is a palindrome or not.
{
    int temp = num;
    int rev = 0;
    while(temp != 0)    //Loop to reverse the number 
    {
        int r = temp%10;
        rev = rev*10 + r;
        temp = temp/10;
    }
    if(rev == num)
        return 1;
    else
        return 0;
}

  static void RangePalindrome(int f, int l) //Function to print the palindrome numbers in a given range.
  {
    printf("Palindrome numbers between %d and %d are: ", f, l);
    for(int i = f; i <= l; i++)
    {
        if(isPalindrome(i))
            printf("%d ", i);
    }
    printf("\n");
  }

int main()
{ 
    int choice;
    do{
      printf("1. Check for Palindrome number \n2. Print Palindrome in a given range\nEnter your choice:");
      scanf("%d", &choice);
    
      if(choice == 1)
      {
         int num;
         printf("Enter a number:");
         scanf("%d", &num);
         if(isPalindrome(num))
             printf("%d is a palindrome number.\n", num);
         else
             printf("%d is not a palindrome number.\n", num);
          printf("Enter 1 to continue or 0 to exit:");
          scanf("%d", &choice);
          break;
      } 
      else if(choice == 2)
        {
            int f, l;
            printf("Enter the range (from and to):"); 
            scanf("%d %d", &f, &l);
            if(f>l)
            {
                printf("Invalid range. Please try again.\n");
                continue;
            }
            RangePalindrome(f, l);
            printf("Enter 1 to continue or 0 to exit:");
            scanf("%d", &choice);
            break;
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
            choice = 1; // Set choice to 1 to continue the loop for valid input
        }
    }while(choice == 1);
    return 0;
}