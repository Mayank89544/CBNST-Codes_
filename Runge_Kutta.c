#include<stdio.h>

float f(float x , float y)
{
    return (y*y - x*x)/(y*y + x*x);
}
int main()
{
    float x0 , y0;
    printf("Enter the value of x0 and y0 : ");
    scanf("%f%f",&x0,&y0);

    int n;
    printf("Enter the no. of steps : ");
    scanf("%d",&n);

    float xn , yn;
    printf("Enter the value of xn to which you want to find yn : ");
    scanf("%f",&xn);

    float h = (xn - x0)/n;
    float k1,k2,k3,k4,k;
    for(int i=0;i<n;i++)
    {
        k1 = h * f(x0 , y0);
        k2 = h * f(x0 + h/2 , y0 + k1/2);
        k3 = h * f(x0 + h/2 , y0 + k2/2);
        k4 = h * f(x0 + h , y0 + k3);
        k = (k1 + 2*k2 + 2*k3 +k4)/6.0;

        yn = y0 + k;
        y0 = yn;
        x0 = x0 + h;
    }

    printf("\nthe answer is : %f",yn);
}