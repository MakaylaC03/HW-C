/*
Makayla Coomer
12/7/23
Print the distance of a line segment
*/
#include <stdio.h>
#include <math.h>

double length(double x1, double y1, double x2, double y2);
double area(double x1, double y1, double x2, double y2, double x3, double y3);

int main(){
    double Tri_Area;
    double X1, X2, X3, Y1, Y2, Y3;
    printf("Enter an X1 coordinate: ");
    scanf("%lf", &X1); 
    printf("Enter an X2 coordinate: ");
    scanf("%lf", &X2);
    printf("Enter an X3 coordinate: ");
    scanf("%lf", &X3);
    printf("Enter a Y1 coordinate: ");
    scanf("%lf", &Y1);
    printf("Enter a Y2 coordinate: ");
    scanf("%lf", &Y2);
    printf("Enter a Y3 coordinate: ");
    scanf("%lf", &Y3);
    Tri_Area = area(X1,Y1,X2,Y2,X3,Y3);
    printf("%lf",Tri_Area);

   
    return 0;

   

}

double length(double x1, double y1, double x2, double y2) {
    double distance;

    distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    return distance;
}

double area(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a = length(x1,y1,x2,y2);
    double b = length(x2,y2,x3,y3);
    double c = length(x3,y3,x1,y1);
    double s = (a + b + c) / 2;
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}

