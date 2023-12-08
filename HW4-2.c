/*
Makayla Coomer
12/8/23
Write a program in C which fills, with random values between 0 and M, a square matrix and outputs the frequency in which numbers occur
as well as the standard deviation. The program continues until a maximum number of tries have been reached or or standard deviation is
smaller than omax
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
    int i, j, k, sum = 0, tries = 0;
    double mean, sd, sigma_max;

    printf("Enter the maximum tolerable standard deviation: ");
    scanf("%lf", &sigma_max);

    do {
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

        if (sd < sigma_max) {
            printf("The mean value is %.2f and the population standard deviation is %.2f.\n", mean, sd);
        } else {
            printf("The standard deviation is %.2f which is greater than the maximum tolerable standard deviation %.2f.\n", sd, sigma_max);
            tries++;
        }
    } while (sd >= sigma_max && tries < 1000);

    if (tries == 1000) {
        printf("The maximum number of tries has been reached.\n");
    }

    return 0;
}