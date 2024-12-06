#include<stdio.h>
#include<math.h>

float f(float x)
{
    return 1/(1+(x*x));
}

float trapezoidal(float low , float high , float sub)
{
    float h = (high - low)/sub;
    float firstSum = f(low) + f(high);
    float totalSum = 0.0;
    float middleSum = 0.0;

    for(int i=1;i<sub;i++)
    {
        middleSum += f(low + i*h);
    }

    middleSum *= 2;
    totalSum += middleSum + firstSum;

    return (h/2)*totalSum;


}

int main()
{
    float low,high,sub;
    printf("Enter the lower limit : ");
    scanf("%f",&low);
    printf("\nenter the upper limit : ");
    scanf("%f",&high);
    printf("\nEnter the subinterval : ");
    scanf("%f",&sub);

    float result = trapezoidal(low,high,sub);
    printf("\nThe answer is : %f",result);
}