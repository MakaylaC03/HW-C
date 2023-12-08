#include <stdio.h>
#include <math.h>

double mysqrt(double r, double e);

int main() {
    double r = 0;
    double e = 1e-6;
    while (1) {
        printf("Enter a positive real number (negative to exit): ");
        scanf("%lf", &r);
        if (r < 0) {
            break;
        }
        double x = mysqrt(r, e);
        printf("The square root of %g is %g\n", r, x);
    }
    return 0;
}

double mysqrt(double r, double e) {
    double x0 = r / 2;
    double xn = 0;
     xn = 0.5 * (x0 + (r / x0));
    do {
        xn = 0.5*(xn+(r/xn));
    } while (fabs(xn - x0) / xn < e);
    return xn;
}