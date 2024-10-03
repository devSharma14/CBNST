#include<stdio.h>
#include<math.h>

double f(double x) {
	return x*x*x*x - x -10;
}

void secant(double x0, double x1, double aerror) {
	double next;
	int count = 0;
	int cur = 2;
	do {
		next = x1 - (f(x1)) * (x1-x0) / (f(x1) - f(x0));
		printf("Iteration %d : x%d : %.6lf : f(x%d) : %.6lf \n", count++, cur, x1, cur, f(x1));
		cur++;
		x0 = x1;
		x1 = next;
	}
	while(fabs(x1-x0) >= aerror);

	printf("Root of the equation is approximately : %.6lf after %d iterations. \n", x1, count);
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

	secant(a,b,aerror);
}