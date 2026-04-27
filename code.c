#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;

    int characters = 0, words = 0, lines = 0;
    int vowels = 0, digits = 0, spaces = 0;

    int inWord = 0; // For accurate word counting

    // Ask user for file name
    printf("Enter file name (with .txt): ");
    scanf("%s", filename);

    // Open file
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Unable to open file!\n");
        return 1;
    }

    // Read file character by character
    while ((ch = fgetc(file)) != EOF) {

        characters++;

        // Count lines
        if (ch == '\n')
            lines++;

        // Count spaces
        if (ch == ' ')
            spaces++;

        // Count digits
        if (isdigit(ch))
            digits++;

        // Count vowels
        char lower = tolower(ch);
        if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
            vowels++;

        // Accurate word count logic
        if (ch != ' ' && ch != '\n' && ch != '\t') {
            if (!inWord) {
                words++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
    }

    fclose(file);

    // Output report
    printf("\n===== TEXT ANALYSIS REPORT =====\n");
    printf("Total Characters : %d\n", characters);
    printf("Total Words      : %d\n", words);
    printf("Total Lines      : %d\n", lines + 1);
    printf("Total Vowels     : %d\n", vowels);
    printf("Total Digits     : %d\n", digits);
    printf("Total Spaces     : %d\n", spaces);

    return 0;
}
