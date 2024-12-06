#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main() {
    int n;
    printf("n : ");
    scanf("%d", &n);
    float x[n], y[n][n];
    printf("x table : \n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &x[i]);
    }
    printf("y table : \n");
    for (int i = 0; i < n; i++) {
        scanf("%f", &y[i][0]);
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }
    printf("\nForward Difference Table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf("%f ", y[i][j]);
        }
        printf("\n");
    }
    
    float point;
    printf("point : ");
    scanf("%f", &point);
    int index = 0;
    for(int i=0; i<n; i++) {
        if(x[i] <= point) {
            index = i;
        }
        else {
            break;
        }
    }
    float h = x[1] - x[0];
    float u = (point - x[index]) / h;
    float p = 1;
    float res = y[index][0];
    for(int i=1; i<n-index; i++) {
        p = p * (u - (i-1));
        res += y[index][i] / tgamma(i+1);
    }
    printf("result : %.2f\n", res);
}
