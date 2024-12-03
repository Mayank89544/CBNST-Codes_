#include<stdio.h>
#include<math.h>

double f(double x)
{
    return x*x*x*x - x - 10;
}

void secant(double x0 , double x1 , double aerror)
{
    double next;
    int iter = 1 , curr = 2;

    do{
        next = x1 - (f(x1) * ((x1 - x0)/(f(x1) - f(x0))));
        printf("\nIteration : %d | x%d : %.4lf | f(x%d) : %.4lf",iter , curr , x1 , curr , f(x1));
        iter++;curr++;
        x0 = x1;
        x1 = next;
    }while(fabs(x0-x1) >= aerror);

    printf("\nThe value is : %.4lf",x1);
}

int main()
{
    double a,b;
    printf("Enter the guess value of a and b : ");
    scanf("%lf%lf",&a,&b);

    while(1)
    {
        if(f(a) * f(b) < 0)
        {
            printf("\nCorrect Guess...");
            break;
        }
        else{
            printf("\nWrong Guess!..Enter again : ");
            scanf("%lf%lf",&a,&b);
        }
    }

    double aerror;
    printf("Enter the allowed error : ");
    scanf("%lf",&aerror);

    secant(a,b,aerror);
}