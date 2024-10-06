#include<stdio.h>
#include<math.h>

float f(float x) {
    return x*x*x*x - x - 10;
}

float g(float x) {
    return pow(10+x, 0.25);
}

// derivative of g
float dg(float x) {
    return pow(x+10, -0.75);
}

int main() {
    float x, x0;
    while(1) {
        printf("Enter x0 -> ");
        scanf("%f", &x0);
        if(fabs(dg(x0)) < 1) {
            printf("Correct ! \n");
            break;
        }
        else {
            printf("Invalid value of x0 ! Try again! \n");
        }
    }

    float aerror;
    int iter = 0;
    printf("Enter allowed error -> ");
    scanf("%f", &aerror);
    x = g(x0);
    ++iter;

    while(fabs(x-x0) >= aerror) {
        x0 = x;
        x = g(x0);
        ++iter;
    }

    printf("Root of equation : %f after %d iterations. \n", x, iter);
}