#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define f1(x , y , z)   (17 - y + (2 * z)) / 20
#define f2(x , y , z)   (-18 - 3 * x + z) / 20
#define f3(x , y , z)   (25 - 2 * x + 3 * y) / 20

int main() {
    float x0 = 0, y0 = 0, z0 = 0;  
    float x1, y1, z1;  
    float aerror;  
    int count = 1;  
    
    printf("Enter the allowed error -> ");
    scanf("%f", &aerror);

    printf("\nIteration\tx\t\t y\t\t z\n");
    do {
        x1 = f1(x0, y0, z0);
        y1 = f2(x1, y0, z0);  // updated x1 passed
        z1 = f3(x1, y1, z0);  // updated x1 and y1 passed
        
        printf("%d\t%f\t %f\t %f\n", count, x1, y1, z1);
        
        if(fabs(x1 - x0) < aerror && fabs(y1 - y0) < aerror && fabs(z1 - z0) < aerror) {
            break;
        }
        
        x0 = x1;
        y0 = y1;
        z0 = z1;
        
        count++;
        
    } while(1);

    printf("\nThe solution is: x = %f, y = %f, z = %f\n", x1, y1, z1);
    return 0;
}
