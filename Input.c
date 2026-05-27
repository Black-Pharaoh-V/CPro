// Program to Take input from a file. File Handling
// TriTea@blackpharaoh

#include <stdio.h>

int main()
{
    char filename[100];
    char text[100];
    FILE *file;

    printf("Enter the name of the file to create (e.g., test.txt)");
    scanf("%s", filename);

    // clear the input buffer so it doesn't skip the next text input
    while (getchar() != '\n')
        ;
    // 2. Open/Create the file in write mode ('w')
    file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening /creating file!\n");
        return 1;
    }

    // 3. Ask the user to write into the file
    printf("\n Enter the text you want to save to the file:\n");
    // fgets reads the whole line including spaces

    fgets(text, sizeof(text), stdin);

    // 4.Write data to the file and close it
    fprint(file, "%s", text);
    fclose(file);

    printf("\n Success! Your text has been written to '%s'.\n", filename);
    return 0;
}