#include<stdio.h>
#include<string.h>
#include<math.h>

float u_cal(float u , int n)
{
    float temp = u;
    for(int i=1;i<n;i++)
    {
        temp = temp * (u+i);
    }
    return temp;
}

int fact(int n)
{
    int f = 1;
    for(int i=2;i<=n;i++)
    {
        f *= i;
    }
    return f;
}

int main()
{
    int n;
    printf("\nEnter the no. of inputs : ");
    scanf("%d",&n);

    float x[n] , y[n][n];
    memset(y,0.0,sizeof(y));

    printf("\nEnter the inputs for X :");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&x[i]);
    }

    printf("\nEnter the inputs for Y : ");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&y[i][0]);
    }

    //Creating the Backward table....

    for(int j=1;j<n;j++)
    {
        for(int i=n-1;i>=j;i--)
        {
            y[i][j] = y[i][j-1] - y[i-1][j-1];
        }
    }

    //Printing the Backward Table.....
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            printf("%f\t",y[i][j]);
        }
        printf("\n");
    }
    float a;
    printf("\nEnter the no. of Interpolation : ");
    scanf("%f",&a);
    float h = x[1] - x[0];
    float u = (a - x[n-1])/h;

    float sum = y[n-1][0];
    for(int i=1;i<n;i++)
    {
        sum += (u_cal(u,i) * y[n-1][i])/fact(i);
    }
    printf("\nThe answer is : %f",sum);
}