#include<stdio.h>
int main()
{
    int n;
    printf("Enter the no. oof inputs : ");
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

    float sigma_x , sigma_y , sigma_xx , sigma_xy , sigma_yy;
    for(int i=0;i<n;i++)
    {
        sigma_x += x[i];
        sigma_y += y[i];
        sigma_xy += x[i] * y[i];
        sigma_xx += x[i] * x[i];
        sigma_yy += y[i] * y[i];
    }

    float b_yx , b_xy;
    b_yx = (n*sigma_xy - sigma_x * sigma_y) / (n * sigma_xx - sigma_x * sigma_x);
    b_xy = (n*sigma_xy - sigma_x * sigma_y) / (n * sigma_yy - sigma_y * sigma_y);

    float mean_x,mean_y;
    mean_x = sigma_x / n;
    mean_y = sigma_y / n;

    float a_xy , a_yx;
    a_xy = mean_x - (b_xy * mean_y);
    a_yx = mean_y - (b_yx * mean_x);

    printf("\nThe equation of y on x is : y - %f = %f(x - %f)",mean_y,b_yx,mean_x);
    printf("\nThe equation of x on y is : x - %f = %f(y - %f)",mean_x , b_xy , mean_y);



}
