/*
Makayla Coomer
12/7/23
Write a program that reads two real numbers X and Y and answers where the point with coordinates
(X, Y ) is in a circle with radius 1.
*/

#include <stdio.h>
#include <math.h>

int main(){
    float add, dis;
    float X, Y;
    printf("Enter an X coordinate: ");
    scanf("%f", &X);  // Change %d to %f
    printf("Enter a Y coordinate: ");
    scanf("%f", &Y);  // Change %d to %f

    add = (X*X) + (Y*Y);
    dis = sqrt(add);

    if(dis < 1){
        printf("The point %f, %f is inside the circle", X, Y);  // Change %d to %f
    }else if(dis == 1){
        printf("The point %f, %f is on the border of the circle", X, Y);  // Change %d to %f
    }else if(dis > 1){
        printf("The point %f, %f is outside the circle", X, Y);  // Change %d to %f
    }else{
        printf("Invalid entry");
    }
    return 0;
}