#include <stdio.h>
#include<math.h>

int main() {
    int n;
    printf("Enter number of data points -> ");
    scanf("%d", &n);

    float x[n], y[n][n];  // 2D matrix for difference table
    printf("Enter values of x: \n");
    for(int i=0; i<n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
    }

    printf("Enter corresponding values of y: \n");
    for(int i=0; i<n; i++) {
        printf("y[%d]: ", i);
        scanf("%f", &y[i][0]);  
    }

    // Step 1: Construct the difference table
    for(int j=1; j<n; j++) {
        for(int i=0; i<n-j; i++) {
            y[i][j] = y[i+1][j-1] - y[i][j-1];  // Calculate forward difference
        }
    }

    // Step 2: Print the difference table
    printf("\nForward Difference Table:\n");
    for(int i=0; i<n; i++) {
        printf("x[%d] = %.2f\t", i, x[i]);
        for(int j=0; j<n-i; j++) {
            printf("%.4f\t", y[i][j]);
        }
        printf("\n");
    }

    // Step 3: Take input for interpolation point
    float point;
    printf("\nEnter value of x to find y: ");
    scanf("%f", &point);

    // Step 4: applying Newton Forward formula
    float h = x[1] - x[0];  // x vale column me 2nd term - 1st term
    float u = (point - x[0]) / h;  // Calculate u
    float res = y[0][0];  // Initialize result with y0
    float p = 1;  // Initialize p for u*(u-1)*(u-2)...

    for(int i=1; i<n; i++) {
        p = p * (u - (i - 1));  // Update p
        res += (p * y[0][i]) / tgamma(i+1);  // Add next term in the interpolation series
    }

    // Step 5: Print the interpolated result
    printf("The interpolated value of y at x = %.2f is %.4f\n", point, res);

    return 0;
}
