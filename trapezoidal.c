#include<stdio.h>

float f(float x) {
    return 1 / (1 + (x*x));  
}

float trapezoidal(float a , float b , int n) {
    float h = (b-a) / n;
    float firstSum = f(a) + f(b);
    float middleSum = 0;
    float totalSum = 0;
    for(int i=1; i<n; i++) {
        middleSum += f(a + i*h);
    }
    middleSum *= 2;
    totalSum += firstSum + middleSum;
    return (h / 2) * totalSum;
}

int main() {
    float low , high;
    int n;
    printf("Enter the lower limit of integration : ");
    scanf("%f", &low);
    printf("Enter the upper limit of integration : ");
    scanf("%f", &high);
    printf("Enter the no of subintervals : ");
    scanf("%d",&n);
    if(n <= 0) {
        printf("Number of subintervals must be > 0. \n");
        return 1;
    }
    float res = trapezoidal(low, high, n);
    printf("The value of the integral is : %.4f \n", res);
}