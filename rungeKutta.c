#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float f(float x , float y) {
    return (y*y - x*x) / (y*y + x*x);
}

int main() {
    float x0 , y0;
    int n;
    printf("Enter inital points x0 and y0 separated by space : ");
    scanf("%f %f", &x0 , &y0);
    printf("Enter the no of steps : ");
    scanf("%d", &n);
    float xn , yn;
    printf("Enter the value of x for which u want y (xn) : ");
    scanf("%f", &xn);
    float k1 , k2 , k3 , k4 , K;
    float h = (xn - x0) / n;
    for(int i = 0; i < n; i++) {
        k1 = h * f(x0 , y0);
        k2 = h * f(x0 + h/2 , y0 + k1/2);
        k3 = h * f(x0 + h/2 , y0 + k2/2);
        k4 = h * f(x0 + h , y0 + k3);
        K = (k1 + 2*k2 + 2*k3 + k4) / 6.0;
        yn = y0 + K;
        y0 = yn;
        x0 = x0 + h;
    }
    printf("The final value of yn is : %.5f \n", yn);
}