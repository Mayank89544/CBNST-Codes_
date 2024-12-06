#include<stdio.h>
#include<math.h>
float f(float x)
{
    return 1/(1+(x*x));
}

float Simpson(float low , float high , int n)
{
    float h = (high - low)/n;
    float FirstSum = f(low) + f(high);
    float totalSum = 0;
    float evenSum = 0;
    float oddSum = 0;

    for(int i=1;i<n;i++)
    {
        if(i%2==0)
        {
            evenSum += f(low + h*i);
        }
        else{
            oddSum += f(low + h*i);
        }
    }

    totalSum += FirstSum;
    evenSum *= 2;
    oddSum *= 4;
    totalSum += evenSum + oddSum;

    return (h/3) * totalSum;
}

int main()
{
    float low , high ;
    int n;
    printf("Enter the lower limit : ");
    scanf("%f",&low);
    printf("\nEnter the upper limit : ");
    scanf("%f",&high);
    printf("\nEnter the no. of subintervals : ");
    scanf("%d",&n);

    float result = Simpson(low , high , n);
    printf("The Answer is : %f",result);
}