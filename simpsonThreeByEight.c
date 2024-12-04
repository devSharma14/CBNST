#include <stdio.h>
#include <math.h>

float f(float x)
{
    return 1 / (1 + (x * x * x * x * x));
}

float simpsonThreeByEight(float low, float high, int n)
{
    float h = (high - low) / n;
    float firstAndLastSum = f(low) + f(high);
    float totalSum = 0;
    totalSum += firstAndLastSum;
    float multiplesSum = 0;
    float remainingSum = 0;
    for (int i = 1; i < n; i++)
    {
        if (i % 3 == 0)
        {
            multiplesSum += f(low + i * h);
        }
        else
        {
            remainingSum += f(low + i * h);
        }
    }
    multiplesSum *= 2;
    remainingSum *= 3;
    totalSum += multiplesSum + remainingSum;
    return (3 * h / 8) * totalSum;
}

int main()
{
    float low, high;
    int n;
    printf("Enter the lower limit of integration : ");
    scanf("%f", &low);
    printf("Enter the upper limit of integration : ");
    scanf("%f", &high);
    printf("Enter the no of subintervals : ");
    scanf("%d", &n);
    if (n % 2 != 0)
    {
        printf("Number of subintervals must be even. \n");
        return 1;
    }
    float res = simpsonThreeByEight(low, high, n);
    printf("The value of the integral is : %.4f \n", res);
}