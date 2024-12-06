#include<stdio.h>
#include<math.h>

float f(float x , float y)
{
    return x+y;
}

int main()
{
    float x0 , y0 , xn;
    int n;
    printf("Enter the value of x0 : ");
    scanf("%f",&x0);
    printf("Enter the value of y0 : ");
    scanf("%f",&y0);

    printf("Enter the value of xn to which you want to find yn : ");
    scanf("%f",&xn);

    printf("Enter the no. of subintervals : ");
    scanf("%d",&n);

    float h = (xn-x0)/n;
    float x = x0 , y = y0;
    float slope = 0.0;
    for(int i=0;i<n;i++)
    {
        slope = f(x,y);
        y = y + h*slope;
        x = x + h;
    }

    printf("\nThe answer is : %f",y);

}