#include<stdio.h>
#include<math.h>

double f(double x) {
    return x*x*x - x - 1;
}

int count = 1;

void bisection(double a, double b, double aerror) {
    double c;

    while((b-a) >= aerror) {
        c = (a+b) / 2;

        if(f(c) == 0.0) {
            printf("Exact root found : %.4lf \n", c);
            return;
        }

        if(f(c) * f(a) < 0) {
            b = c;
        }
        else {
            a = c;
        }   

        printf("%d iteration : x : %.4lf and f(x) : %.4lf \n", count++, c, f(c) );
    }

    printf("The root is approximately : %.4lf after %d iterations. \n", c, count);

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

    double aerror;
    printf("Enter allowed error -> ");
    scanf("%lf", &aerror);

    bisection(a,b,aerror);
}