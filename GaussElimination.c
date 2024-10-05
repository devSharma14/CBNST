#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main() {
    int n; 
    printf("Enter the size of the matrix -> ");
    scanf("%d", &n);
    float mat[n][n+1];

    // Step 1 : Input the matrix
    printf("Enter details for the augmented matrix : \n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n+1; j++) {
            printf("mat[%d][%d] -> ", i, j);
            scanf("%f", &mat[i][j]);
        }
    }
    printf("\nMatrix : \n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n+1; j++) {
            printf("%f \t", mat[i][j]);
        }
        printf("\n");
    }

    // Step 2 : Convert it into upper triangular matrix
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(j > i) {
                float coeff = mat[j][i] / mat[i][i];
                for(int k=0; k<n+1; k++) {
                    mat[j][k] = mat[j][k] - coeff * mat[i][k];
                }
            }
        }
        printf("Intermediate form : \n");
        for(int i=0; i<n; i++) {
            for(int j=0; j<n+1; j++) {
                printf("%f \t", mat[i][j]);
            }
            printf("\n");
        }
    }
   printf("\nUpper triangular matrix : \n");
   for(int i=0; i<n; i++) {
        for(int j=0; j<n+1; j++) {
            printf("%f \t", mat[i][j]);
        }
        printf("\n");
    }

    // Step 3 : Apply backward substitution
    float ans[n];
    for(int i=n-1; i>=0; i--) {
        ans[i] = mat[i][n];
        for(int j=i+1; j<n; j++) {
            ans[i] = ans[i] - mat[i][j] * ans[j];
        }
        ans[i] = ans[i] / mat[i][i];
    }

    // Step 4 : Print the solution
    printf("\nSolution : \n");
    for(int i=0; i<n; i++) {
        printf("ans[%d] : %.2f \n", i, ans[i]);
    }

}