#include<stdio.h>
#include<math.h>

double f(double x)
{
    return x*x*x*x - x - 10;
}

double g(double x)
{
    return pow((10+x),0.25);
}

double dg(double x)
{
    return 0.25 * (pow((10+x),-0.75));
}

int main()
{
    double x , x0;
    printf("Enter the calue of x0 : ");
    scanf("%lf",&x0);

    while(1)
    {
        if(fabs(dg(x0)) < 1)
        {
            printf("\nCorrect Guess..");
            break;
        }
        else{
            printf("Wrong Guess!...");
            scanf("%lf",&x0);
        }
    }
    int iter = 1;
    x = g(x0);
    double aerror;
    printf("\nEnter the allowed error : ");
    scanf("%lf",&aerror);

    while(fabs(x - x0) >= aerror)
    {
        x0 = x;
        x = g(x0);
        printf("\nIteration : %d---x0 : %.4lf and x : %.4lf and g(x) : %.4lf",iter , x0 , x , g(x));
        iter++;
    }
    printf("\nThe value is %.4lf in iteration : %d",x,iter);
    //Remeber when you will run this file...To run it you need to write gcc Iteration.c -lm
}
