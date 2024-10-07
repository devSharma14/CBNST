#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float f1(float y,float z)
{
    return (44-y-2*z)/10;
}

float f2(float x,float z)
{
    return (51-2*x-z)/10;
}

float f3(float x,float y)
{
    return (61-x-2*y)/10;  
}


int main()
{
    int m, n;
    printf("Enter the number of equations (rows) and variables (columns): ");
    scanf("%d%d", &m, &n);

    float mat[m][n+1];
    
    printf("Enter the augmented matrix coefficients (including the constants): \n");
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j <= n; j++) 
        {
            scanf("%f", &mat[i][j]);
        }
    }

    int flag=1;
    for(int i=0;i<m;i++)
    {
        float check=fabs(mat[i][i]);
        float sum=0;
        for(int j=0;j<n;j++)
        {
            if(i!=j)
            {
                sum+=fabs(mat[i][j]);
            }
        }
        if(check<sum)
        {
            flag=0;
            break;
        }
    }

    if(flag)
    {
        float ex,ey,ez;
        printf("\n\nEnter allowed error in x : ");
        scanf("%d",&ex);
        printf("Enter allowed error in y : ");
        scanf("%d",&ey);
        printf("Enter allowed error in z : ");
        scanf("%d",&ez);
        float e1,e2,e3;
        float x=0,y=0,z=0;
        do
        {
            float tempx=x;
            float tempy=y;
            float tempz=z;
            x=f1(y,z);
            y=f2(x,z);
            z=f3(x,y);
            e1=fabs(x-tempx);
            e2=fabs(y-tempy);
            e3=fabs(z-tempz);
        } while ((fabs(e1)>fabs(ex)&&fabs(e2)>fabs(ey)&&fabs(e3)>fabs(ez)));

        printf("\n\nSolution : \n");
        printf("\n%0.5f",x);
        printf("\n%0.5f",y);
        printf("\n%0.5f",z);
    }
    else
    {
        printf("\nSolution does not extis");
    }
}