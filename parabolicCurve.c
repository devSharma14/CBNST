#include <stdio.h>
#include <stdlib.h>

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
    float mat[3][4];
    mat[0][0] = n;
    mat[0][1] = sigmaX;
    mat[0][2] = sigmaXX;
    mat[0][3] = sigmaY;

    mat[1][0] = sigmaX;
    mat[1][1] = sigmaXX;
    mat[1][2] = sigmaXXX;
    mat[1][3] = sigmaXY;

    mat[2][0] = sigmaXX;
    mat[2][1] = sigmaXXX;
    mat[2][2] = sigmaXXXX;
    mat[2][3] = sigmaXXY;

    printf("matrix initially : \n");
    
    int N = 3;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N+1; j++)
        {
            printf("%f ", mat[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            float coeff = mat[j][i] / mat[i][i];
            for (int k = 0; k < N + 1; k++)
            {
                mat[j][k] -= coeff * mat[i][k];
            }
        }
    }

    printf("\nmatrix after operations : \n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N+1; j++)
        {
            printf("%f ", mat[i][j]);
        }
        printf("\n");
    }

    float ans[3];
    for (int i = N - 1; i >= 0; i--)
    {
        ans[i] = mat[i][N];
        for (int j = i + 1; j < N; j++)
        {
            ans[i] = ans[i] - mat[i][j] * ans[j];
        }
        ans[i] /= mat[i][i];
    }

    for (int i = 0; i < N; i++)
    {
        printf("%.2f ", ans[i]);
    }

    printf("Equation : y = %.2f + %.2f(x) + %.2f(x*x)" , ans[0],ans[1],ans[2]);

    return 0;
}
