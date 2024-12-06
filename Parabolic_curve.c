#include<stdio.h>
int main()
{
    int n;
    printf("Enter the no. of data : ");
    scanf("%d",&n);

    float x[n],y[n];
    printf("Enter the data points of x : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&x[i]);
    }

    printf("Enter the data points of y : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&y[i]);
    }

    float sigma_x=0 , sigma_y=0 , sigma_xx=0 , sigma_xy=0 , sigma_xxx=0 , sigma_xxxx=0 , sigma_xxy=0;
    for(int i=0;i<n;i++)
    {
        sigma_x += x[i];
        sigma_y += y[i];
        sigma_xy += x[i] * y[i];
        sigma_xx += x[i] * x[i];
        sigma_xxx += x[i] * x[i] * x[i];
        sigma_xxxx += x[i] * x[i] * x[i] * x[i];
        sigma_xxy += x[i] * x[i] * y[i];
    }

    float mat[3][4];

    mat[0][0] = n;
    mat[0][1] = sigma_x;
    mat[0][2] = sigma_xx;
    mat[0][3] = sigma_y;

    mat[1][0] = sigma_x;
    mat[1][1] = sigma_xx;
    mat[1][2] = sigma_xxx;
    mat[1][3] = sigma_xy;

    mat[2][0] = sigma_xx;
    mat[2][1] = sigma_xxx;
    mat[2][2] = sigma_xxxx;
    mat[2][3] = sigma_xxy;

    int N = 3;
    printf("\nInitially matrix : \n");
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%f\t",mat[i][j]);
        }
        printf("\n");
    }

    //Applying The Operations...

    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            float coeff = mat[j][i]/mat[i][i];
            for(int k=0;k<N+1;k++)
            {
                mat[j][k] -= coeff * mat[i][k];
            }
        }
    }

    printf("\nAfter Operations : \n");
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            printf("%f\t",mat[i][j]);
        }
        printf("\n");
    }

    float ans[3];
    for(int i=N-1;i>=0;i--)
    {
        ans[i] = mat[i][N];
        for(int j=i+1;j<N;j++)
        {
            ans[i] = ans[i]-mat[i][j] * ans[j];
        }
        ans[i] = ans[i]/mat[i][i];
    }

    printf("\nequation : y = %f + %f(x) + %f(x*x)" , ans[0],ans[1],ans[2]);
}