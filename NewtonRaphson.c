#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double f(double x) {
    return x*x*x*x - x - 10;
}

double derivative(double x) {
    return 4*x*x*x - 1;
}

void newtonRaphson(double x0, double aerror) {
    double prev, next;
    int count = 0;
    int cur = 2;
    do {
        prev = x0;
        next = x0 - f(x0) / derivative(x0);

        printf("Iteration %d : x%d : %.6lf : next : %.6lf \n", count++, cur, x0, next);
        cur++;

        x0 = next;
    }
    while(fabs(x0-prev) >= aerror);

    printf("Root of the equation is approximately : %.6lf after %d iterations. \n", x0, count);
}

int main() {
    double a,b;

    while(1) {
        printf("Enter the first guess -> ");
        scanf("%lf", &a);
        printf("Enter the second guess -> ");
        scanf("%lf", &b);

        if(f(a) * f(b) < 0) {
            break;
        }
        else {
            printf("Invalid interval! f(a) and f(b) must have opposite signs\n");
        }

    }
    double num1 = f(a);
    double num2 = f(b);

    double x0;
    if(fabs(num1) < fabs(num2)) {
        x0 = num1;
    }
    else {
        x0 = num2;
    }
    printf("x0 : %lf \n", x0);
    double aerror = 0.0;
    printf("Enter the allowed error -> ");
    scanf("%lf", &aerror);
    newtonRaphson(x0, aerror);
}