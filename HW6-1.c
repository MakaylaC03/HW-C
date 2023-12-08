#include <stdio.h>
#include <ctype.h>
#include <string.h>

// A function to print a word in capital letters inside a box of *
void print_word(char *word);

// The main function
int main()
{
    char word[100];
    // Ask the user to type a word
    printf("Type a word: ");
    scanf("%s", word);
    // Loop until the user types "exit"
    while (strcmp(word, "exit") != 0)
    {
        // Print the word in capital letters inside a box of *
        print_word(word);
        // Ask the user to type another word
        printf("Type another word: ");
        scanf("%s", word);
    }
    return 0;
}

void print_word(char *word)
{
    int i, j, len;
    // Convert the word to upper case
    for (i = 0; word[i] != '\0'; i++)
    {
        word[i] = toupper(word[i]);
    }
    // Get the length of the word
    len = strlen(word);
    // Print the top border of the box
    for (i = 0; i < len + 4; i++)
    {
        printf("*");
    }
    printf("\n");
    // Print the word with spaces and * on both sides

    for (i = 0; i < len; i++)
    {
        printf("* %c ", word[i]);
    }
    printf("*\n");
    // Print the bottom border of the box
    for (i = 0; i < len + 4; i++)
    {
        printf("*");
    }
    printf("\n");
}