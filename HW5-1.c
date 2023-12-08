/*
Makayla Coomer
12/8/23
Taken in user input and then print the frequency and percentage of which characters are used
*/


#include <stdio.h>
#include <ctype.h>
#define MAX_CHARS 26

int main() {
    int c, i, total = 0;
    int freq[MAX_CHARS] = {0};

    while ((c = getchar()) != '/') {
        if (isalpha(c)) {
            freq[tolower(c) - 'a']++;
            total++;
        }
    }

    printf("Letter\tFrequency\tPercentage\n");

    for (i = 0; i < MAX_CHARS; i++) {
        if (freq[i] > 0) {
            printf("%c\t%d\t\t%.2f%%\n", i + 'a', freq[i], (double)freq[i] / total * 100);
        }
    }

    return 0;
}