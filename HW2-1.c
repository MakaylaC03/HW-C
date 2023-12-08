/*Makayla Coomer
12/7/23
Check if input is  a perfect number
*/
#include <stdio.h>

int main() {
    int num, i, sum, j;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Using for loop
    sum = 0;
    for (i = 1; i < num; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    if (sum == num) {
        printf("%d is a perfect number using for loop.\n", num);
    } else {
        printf("%d is not a perfect number using for loop.\n", num);
    }

    // Using while loop
    sum = 0;
    i = 1;
    while (i < num) {
        if (num % i == 0) {
            sum += i;
        }
        i++;
    }
    if (sum == num) {
        printf("%d is a perfect number using while loop.\n", num);
    } else {
        printf("%d is not a perfect number using while loop.\n", num);
    }

    // Using do-while loop
    sum = 0;
    i = 1;
    do {
        if (num % i == 0) {
            sum += i;
        }
        i++;
    } while (i < num);
    if (sum == num) {
        printf("%d is a perfect number using do-while loop.\n", num);
    } else {
        printf("%d is not a perfect number using do-while loop.\n", num);
    }

    return 0;
}