// Program to create a menu driven file reading system. File Handling.
// TriTea@blackpharaoh

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char filename[100];
    char ch;
    int choice;
    FILE *file;

    // 1. Get the file name from user
    printf("Enter the name of the file to read (e.g. tet.txt)");
    scanf("%s", filename);

    // 2. Display selection menu
    printf("\n-- File Read Menu --\n");
    printf("1. Read direclty in terminal.\n");
    printf("2. Open the file in text editor.\n");
    printf("Enter your choice:\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        // Open file for reading
        file = fopen(filename, "r");
        if (file == NULL)
        {
            printf("\nError: Could not open file. Try Again.");
            return 1;
        }
        printf("\n-- File Content --\n");
        while ((ch = fget(file)) != EOF)
            putchar(ch);
        pritnf("\n -- File End --\n");

        fclose(file);
        break;

    case 2:
        printf("\n Opening file externally \n");
        char command[150];

// System command to open file based on OS.
#ifdef _WIN32
        sprintf(command, "start %s", filename); // windows
#elif __APPLE__
        sprintf(command, "open %s", filename); // macOS
#else
        sprintf(command, "xdg-open %s", filename);
#endif

        system(command);
        break;

    default:
        printf("Invalid Input\n");
    }
    return 0;
}