#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    float x[n], y[n];
    printf("Enter x data points: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }
    printf("Enter y data points: ");
    for (int i = 0; i < n; i++) {
        scanf("%f", &y[i]);
    }
    float sigmaX = 0, sigmaY = 0, sigmaXY = 0, sigmaXX = 0;
    for (int i = 0; i < n; i++) {
        sigmaX += x[i];
        sigmaY += y[i];
        sigmaXX += x[i] * x[i];
        sigmaXY += x[i] * y[i];
    }
    float b = (n * sigmaXY - sigmaX * sigmaY) / (n * sigmaXX - sigmaX * sigmaX);
    float a = (sigmaY - b * sigmaX) / n;
    printf("\nThe linear curve fit equation is: y = %.2f + %.2fx\n", a, b);
    return 0;
}
