#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main() {
	int n;
	printf("n : ");
	scanf("%d", &n);
	float mat[n][n+1];
	printf("Enter the matrix : \n");
	for(int i=0; i<n; i++) {
		for(int j=0; j<n+1; j++) {
			scanf("%f", &mat[i][j]);
		}
	}
	printf("Matrix initially : \n");
	for(int i=0; i<n; i++) {
		for(int j=0 ; j <n+1; j++) {
			printf("%f ", mat[i][j] );
		}
		printf("\n");
	}
	printf("\n");
	for(int i=0; i<n; i++) {
		float pivot = mat[i][i];
		for(int j=0; j<n+1; j++) {
			mat[i][j] /= pivot;
		}
		for(int j=0; j < n; j++) {
			if(i != j) {
				float coeff = mat[j][i];
				for(int k=0; k<n+1; k++) {
					mat[j][k] -= coeff * mat[i][k];
				}
			}

		}
	}
	printf("\nMatrix after : \n");
	for(int i=0; i<n; i++) {
		for(int j=0 ; j <n+1; j++) {
			printf("%f ", mat[i][j] );
		}
		printf("\n");
	}
	printf("\nSolution : ");
	for(int i=0; i<n; i++) {
		printf("%f ", mat[i][n]);
	}
}
