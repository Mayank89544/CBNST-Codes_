#include<stdio.h>
#include<math.h>

float f(float x)
{
    return 1/(1+x*x);
}

float Simpson(float low , float upper , int n)
{
    float h = (upper - low)/n;
    float firstSum = f(low) + f(upper);
    float middleSum = 0;
    float remainingSum = 0;
    float totalSum = firstSum;

    for(int i=1;i<n;i++)
    {
        if(i%3 == 0)
        {
            middleSum += f(low + i*h);
        }
        else
        {
            remainingSum += f(low + i*h);
        }
    }

    middleSum *= 2;
    remainingSum *= 3;
    totalSum += middleSum + remainingSum;

    return (3*h/8)*totalSum;
}

int main()
{
    float low , upper;
    int n;
    printf("Enter the lower limit : ");
    scanf("%f",&low);
    printf("Enter the upper limit : ");
    scanf("%f",&upper);
    printf("Enter the no. of steps : ");
    scanf("%d",&n);

    float result = Simpson(low , upper , n);
    printf("\nThe answer is : %f",result);
}