#include<stdio.h>

int main()
{
    int n;
    printf("Enter the size of matrix : ");
    scanf("%d",&n);

    float mat[n][n+1];
    
    printf("\nEnter the values in the matrix : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            printf("Enter value for mat[%d][%d] : ",i,j);
            scanf("%f",&mat[i][j]);
        }
    }

    printf("\nThe entered Matrix is : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            printf("%f\t",mat[i][j]);
        }
        printf("\n");
    }

    //Now to make it upper triangular matrix ....

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j > i)
            {
                float coeff = mat[j][i]/mat[i][i];
                for(int k=0;k<n+1;k++)
                {
                    mat[j][k] = mat[j][k] - coeff * mat[i][k];
                }
            }
        }
    }

    printf("\nUpper Triangular....Matrix is : \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            printf("%f\t",mat[i][j]);
        }
        printf("\n");
    }

    //To get the answer....applying Backward Substitution
    float ans[n];
    for(int i=n-1 ; i>=0 ; i--)
    {
        ans[i] = mat[i][n];
        for(int j=i+1 ; j<n ; j++)
        {
            ans[i] = ans[i] - mat[i][j] * ans[j];
        }
        ans[i] = ans[i] / mat[i][i];
    }

    printf("\nAnswers : ");
    for(int i=0;i<n;i++)
    {
        printf("\n%f",ans[i]);
    }

    return 0;
}