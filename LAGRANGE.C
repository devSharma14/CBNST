#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    printf("n : ");
    int n;
    scanf("%d", &n);
    float x[n], y[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter x[%d] : ", i + 1);
        scanf("%f", &x[i]);
        printf("Enter y[%d] : ", i + 1);
        scanf("%f", &y[i]);
    }
    float result = 0;
    float X;
    printf("Enter x for which you want to find y : ");
    scanf("%f", &X);
    for (int i = 0; i < n; i++)
    {
        float numerator = 1.0, denominator = 1.0;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                numerator *= (X - x[j]);
                denominator *= (x[i] - x[j]);
            }
        }
        result += (numerator * y[i]) / denominator;
    }
    printf("Result is : %f \n", result);
    return 0;
}
