#include <stdio.h>
#include <math.h>

float f(float x, float y) {
    return (y - x) / (y + x);
}

int main() {
    float x0, y0, xn;
    int n;
    printf("Enter x0 (initial value of x): ");
    scanf("%f", &x0);
    printf("Enter y0 (initial value of y): ");
    scanf("%f", &y0);
    printf("Enter the number of subintervals: ");
    scanf("%d", &n);
    printf("Enter the value of x at which you want to find yn: ");
    scanf("%f", &xn);
    float h = (xn - x0) / n;
    float x = x0, y = y0;
    for (int i = 0; i < n; i++) { 
        y = y + h * f(x, y); // Calculate y(i+1) = y(i) + h * f(x(i), y(i))
        x = x + h;           // Update x to x(i+1)
    }
    printf("Value of y at x = %.4f is %.4f\n", xn, y);
    return 0;
}
