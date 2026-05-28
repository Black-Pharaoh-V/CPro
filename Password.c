// Program to design a Random Password generation system.
// TriTea@blackpharaoh

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define Size 4096

int main()
{
    // 1. Character pool definition
    char pool[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890!@#$^&*()_+[]{}|;:,.<>?";
    int pool_length = strlen(pool);
    int length, i;
    char choice;
    FILE *file;
    char write_buffer[Size];

    // Seed the standard pseudo- random generator
    srand(time(NULL));

    // Gather requirements
    printf("Enter desired password length: ");
    scanf("%d", &length);

    if (length < 4 || length > 10)
    {
        printf("Password length must be in 4 and 10 Characters.\n");
        return 1;
    }

    // Allocate array dynamically on stack framework boundary.
    char Password[100];
    // 3. Loop and build random string matrix.
    for (int i = 0; i < length; i++)
    {
        Password[i] = pool[rand() % pool_length];
    }
    Password[length] = '/0'; // Explicit Null-terminator setup for printing safely
    printf("\nGenerated Password: %s\n", Password);

    // 4.File save confirmation prompt layout.
    printf("\nDo you want to save this password to 'Password.txt'?(y/n): ");
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        file = fopen("Password.txt", "a");
        if (file == NULL)
        {
            printf("Error Opening /Creating target password log file!\n");
            return 1;
        }

        // Apply efficient full system block streaming buffer configuration
        setvbuf(file, write_buffer, _IOFBF, Size);

        fputs("Password: ", file);
        fputs(Password, file);
        fputs("\n", file);

        fclose(file);
        printf("Success! Password securely appended to 'Password.txt'.\n");
    }
    else
    {
        printf("Password was not saved.\n");
    }
    return 0;
}