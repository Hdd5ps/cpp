// Kamal, Jonathan, Ayan
// csc1180 may 1st, 2025
// This program counts the number of words and non-space characters read from a file "input.txt", excluding the newline character.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    // char *filename = "input.txt"; we can use this but it's not necessary
    file = fopen("input.txt", "r"); // used fopen instead of open for c

    if (file == NULL) // it was missing inequality operator
    {
        printf("Can't open file\n"); // this was missing a semicolon
        return 1;                    // missing a semicolon
    }

    int words = 1, chars = 1; // words should start at 1 to count the first word, and chars at 1 to count the first character
    char ch;

    while ((ch = fgetc(file)) != EOF)
    {
        chars++;
        if (ch == ' ' || ch == '\n' || ch == '\t') // added tab character
        {
            // add words
            words++;
        }
    }

    fclose(file); // it was missing a semicolon

    printf("Words: %d\n", words);                  // wrong variable name word
    printf("Characters (no spaces): %d\n", chars - words); // word variable name was wrong

    return 0;
}