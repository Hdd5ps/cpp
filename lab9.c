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

        // Any kind of spacing (space, tab, new line, etc.) should not be considered as part of the character count.
        if (ch == ' ' || ch == '\n' || ch == '\t')
        {
            chars--; // decrement chars for spaces
        }

        // any standalone punctuation (for example - the preceding dash), this isn’t considered a word, either.  Print out the number of words in the document, as well as the number of non-spaced characters.
        if (ch == '.' || ch == ',' || ch == ';' || ch == ':' || ch == '!' || ch == '?' || ch == '-' || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}')
        {
            words--; // decrement words for punctuation
        }

    }

    fclose(file); // it was missing a semicolon


    // print to screen
    printf("Words: %d\n", words);                  // wrong variable name word
    printf("Characters (no spaces): %d\n", chars - 1); // we don't need the word variable here


    // print out to a document
    FILE *outputFile;
    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL)
    {
        printf("Can't open file\n");
        return 1;
    }
    fprintf(outputFile, "Words: %d\n", words);
    fprintf(outputFile, "Characters (no spaces): %d\n", chars - 1);
    fclose(outputFile); // it was missing a semicolon

    return 0;
}