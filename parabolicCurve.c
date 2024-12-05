#include <stdio.h>
#include <stdlib.h>

void gaussElimination(float mat[3][4], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            float coeff = mat[j][i] / mat[i][i];
            for (int k = 0; k <= n; k++)
            {
                mat[j][k] = mat[j][k] - coeff * mat[i][k];
            }
        }
    }
    printf("\nUpper triangular matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            printf("%f \t", mat[i][j]);
        }
        printf("\n");
    }
    float ans[n];
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = mat[i][n];
        for (int j = i + 1; j < n; j++)
        {
            ans[i] -= mat[i][j] * ans[j];
        }
        ans[i] = ans[i] / mat[i][i];
    }
    printf("\nSolution:\n");
    printf("a (constant term) = %.2f\n", ans[0]);
    printf("b (linear term) = %.2f\n", ans[1]);
    printf("c (quadratic term) = %.2f\n", ans[2]);
}

int main()
{
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    float x[n], y[n];
    printf("Enter x data points: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }
    printf("Enter y data points: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &y[i]);
    }
    float sigmaX = 0, sigmaY = 0, sigmaXY = 0, sigmaXX = 0, sigmaXXX = 0, sigmaXXXX = 0, sigmaXXY = 0;
    for (int i = 0; i < n; i++)
    {
        sigmaX += x[i];
        sigmaY += y[i];
        sigmaXX += x[i] * x[i];
        sigmaXY += x[i] * y[i];
        sigmaXXX += x[i] * x[i] * x[i];
        sigmaXXXX += x[i] * x[i] * x[i] * x[i];
        sigmaXXY += x[i] * x[i] * y[i];
    }
    float mat[3][4] = {
        {n, sigmaX, sigmaXX, sigmaY},           // Σy = aΣ1 + bΣx + cΣx^2
        {sigmaX, sigmaXX, sigmaXXX, sigmaXY},  // Σxy = aΣx + bΣx^2 + cΣx^3
        {sigmaXX, sigmaXXX, sigmaXXXX, sigmaXXY} // Σx^2y = aΣx^2 + bΣx^3 + cΣx^4
    };
    gaussElimination(mat, 3);
    return 0;
}
