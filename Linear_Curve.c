#include<stdio.h>
int main()
{
    int n;
    printf("Enter the no. of inputs : ");
    scanf("%d",&n);

    float x[n],y[n];
    printf("Enter the data point of x : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&x[i]);
    }

    printf("Enter the data points of y : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&y[i]);
    }

    float sigma_x , sigma_y , sigma_xx , sigma_xy;
    for(int i=0;i<n;i++)
    {
        sigma_x += x[i];
        sigma_y += y[i];
        sigma_xx += x[i] * x[i];
        sigma_xy += x[i] * y[i];
    }

    float b = (n * sigma_xy - sigma_x * sigma_y) / (n * sigma_xx - sigma_x * sigma_x);
    float a = (sigma_y - b * sigma_x) / n;

    printf("\nThe equation will be y = %f + %fx",a,b);
}