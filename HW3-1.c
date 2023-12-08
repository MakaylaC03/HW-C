/*
Makayla Coomer
12/7/23
Print the distance of a line segment
*/
#include <stdio.h>
#include <math.h>

double length(double x1, double y1, double x2, double y2) {
    double distance;

    distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    return distance;
}

int main(){
    double dis;
    double X1, X2, Y1, Y2;
    printf("Enter an X1 coordinate: ");
    scanf("%lf", &X1); 
    printf("Enter an X2 coordinate: ");
    scanf("%lf", &X2);
    printf("Enter a Y1 coordinate: ");
    scanf("%lf", &Y1);
    printf("Enter a Y2 coordinate: ");
    scanf("%lf", &Y2);

    dis = length(X1,X2,Y1,Y2);
    printf("%lf", dis);
    return 0;

   

}