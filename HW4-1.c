
/*
Makayla Coomer
12/8/23
Write a program in C which fills, with random values between 0 and M, a square matrix and outputs the frequency in which numbers occur
as well as the standard deviation
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define N 3
#define M 10

int main() {
    int r[N][N];
    int freq[M + 1] = {0};
    int i, j, k, sum = 0;
    double mean, sd;

    srand(time(NULL));
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            r[i][j] = rand() % (M + 1);
            freq[r[i][j]]++;
            sum += r[i][j];
        }
    }

    mean = (double)sum / (N * N);

    for (k = 0; k <= M; k++) {
        if (freq[k] > 0) {
            printf("The number %d occurs %d times.\n", k, freq[k]);
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            sd += pow(r[i][j] - mean, 2);
        }
    }

    sd = sqrt(sd / (N * N));

    printf("The mean value is %.2f and the population standard deviation is %.2f.\n", mean, sd);
    return 0;
}