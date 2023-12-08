/*
Makayla Coomer
12/7/23
Write a program that reads two natural numbers, A and B, and finds if one of the two is divisible by
17 and the other is divisible by 42 at the same time.
*/

#include <stdio.h>

int main() {
    int A, B;

    printf("Enter the value of A: ");
    scanf("%d", &A);

    printf("Enter the value of B: ");
    scanf("%d", &B);

    if ((A % 17 == 0 && B % 42 == 0) || (A % 42 == 0 && B % 17 == 0)) {
        printf("One of the numbers is divisible by 17 and the other is divisible by 42.\n");
    } else {
        printf("Neither of the numbers is divisible by 17 and the other is divisible by 42.\n");
    }

    return 0;
}