#include<stdio.h>
int main()
{
    int n;
    printf("Enter the no. of inputs : ");
    scanf("%d",&n);

    float x[n], y[n];
    printf("\nEnter the values of x and y : ");
    for(int i=0;i<n;i++)
    {
        scanf("%f%f",&x[i],&y[i]);
    }

    //Printing the Values....
    for(int i=0;i<n;i++)
    {
        printf("%f\t%f\n",x[i],y[i]);
    }

    float result = 0.0;
    float a;
    printf("\nEnter the value of x for which You want to find y : ");
    scanf("%f",&a);

    for(int i=0;i<n;i++)
    {
        float num=1.0 , den=1.0;
        for(int j=0;j<n;j++)
        {
            if(i != j)
            {
                num *= (a - x[j]);
                den *= (x[i] - x[j]);
            }
        }
        result += (num * y[i])/den;
    }

    printf("\nThe value of y : %f for value x : %f ",result,a);
}