#include<stdio.h>
#include<math.h>

double f(double x)
{
    return x*x*x*x - x - 10;
}

double d(double x)
{
    return 4*x*x*x - 1;
}

void NewtonRaphson(double x0 , double aerror)
{
    double prev , next;
    int iter = 0 , count = 2;

    do{
        prev = x0;
        next = x0 - f(x0)/d(x0);
        printf("\nIteration : %d | x%d : %.4lf | next : %.4lf",iter , count , x0 , next);
        x0 = next;
        iter++;count++;
    }while(fabs(x0-prev) >= aerror);
    printf("\nThe approx. roots of the values are %.4lf",x0);
}

int main()
{
    double a , b;
    printf("Enter the value of a and b : ");
    scanf("%lf%lf",&a,&b);

    while(1)
    {
        if(f(a) * f(b) < 0)
        {
            printf("\nCorrect Guess..");
            break;
        }
        else{
            printf("\nWrong Guess!...Enter the values again");
            scanf("%lf%lf",&a,&b);
        }
    }

    double num1 , num2;
    num1 = f(a);
    num2 = f(b);

    double x0;

    if(fabs(num1) < fabs(num2))
    {
        x0 = num1;
    }
    else
    {
        x0 = num2;
    }

    double aerror;
    printf("\nEnter the allowed error : ");
    scanf("%lf",&aerror);

    NewtonRaphson(x0,aerror);
}