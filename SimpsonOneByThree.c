#include<stdio.h>
#include<math.h>

float f(float x) {
    return log(x);
}

float simpsonOneBythree(float low , float high , int n) {
    float h = (high - low) / n;
    float firstAndLastSum = f(low) + f(high);
    float totalSum = 0;
    float evenSum = 0;
    float oddSum = 0;
    for(int i=1; i<n; i++) {
        if(i%2 == 0) {
            evenSum += f(low + i*h);
        }
        else {
            oddSum += f(low + i*h);
        }
    }
    evenSum *= 2;
    oddSum *= 4;
    totalSum += firstAndLastSum;
    totalSum += evenSum + oddSum;
    return (h / 3) * totalSum;
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
    if(n % 2 != 0) {
        printf("Number of subintervals must be even. \n");
        return 1;
    }
    float res = simpsonOneBythree(low, high, n);
    printf("The value of the integral is : %.4f \n", res);
}