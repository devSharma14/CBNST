#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    int n;
    printf("Enter n : ");
    scanf("%d" , &n);
    float x[n] , y[n];
    printf("Enter x points : ");
    for(int i = 0; i<n; i++) {
        scanf("%f", &x[i]);
    }
    printf("Enter y points : ");
    for(int i=0; i<n; i++) {
        scanf("%f", &y[i]);
    }
    float sigmaX = 0 , sigmaY = 0 , sigmaXX = 0 , sigmaYY = 0 , sigmaXY = 0;
    for(int i = 0 ; i<n; i++) {
        sigmaX += x[i];
        sigmaY += y[i];
        sigmaXY += (x[i] * y[i]);
        sigmaYY += (y[i] * y[i]);
        sigmaXX += (x[i] * x[i]);
    }
    float b_yx = 0 , b_xy = 0;
    b_yx = (n*sigmaXY - sigmaX * sigmaY) / (n*sigmaXX - sigmaX * sigmaX);
    b_xy = (n*sigmaXY - sigmaX*sigmaY) / (n*sigmaYY - sigmaY * sigmaY);
    float mean_x = sigmaX / n;
    float mean_y = sigmaY / n;
    float a_yx = mean_y - (b_yx * mean_x);
    float a_xy = mean_x - (b_xy * mean_y);
    printf("Equation of y on x : y - %.2f = %.2f(x - %.2f) \n", mean_y, b_yx, mean_x);
    printf("Equation of x on y : x - %.2f = %.2f(y - %.2f) \n", mean_x, b_xy, mean_y);
}