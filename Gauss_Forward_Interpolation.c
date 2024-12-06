#include <stdio.h>
#include <stdlib.h>

// Function to calculate factorial
int fact(int n) {
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

// Function to calculate u terms for Gauss Forward
float u_cal(float u, int n) {
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u - i);
    return temp;
}

int main() {
    int n;
    printf("Enter the number of data points (n): ");
    scanf("%d", &n);

    float x[n], y[n][n];
    
    // Input the x and y values
    printf("Enter the values of x:\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &x[i]);
    
    printf("Enter the values of y:\n");
    for (int i = 0; i < n; i++)
        scanf("%f", &y[i][0]);

    // Creating the forward difference table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++)
            y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
    }

    // Displaying the forward difference table
    printf("\nForward Difference Table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++)
            printf("%0.2f\t", y[i][j]);
        printf("\n");
    }

    // Interpolation point
    float value;
    printf("\nEnter the value of x for interpolation: ");
    scanf("%f", &value);

    // Calculate u
    float h = x[1] - x[0];
    float u = (value - x[0]) / h;

    // Apply Gauss Forward Interpolation formula
    float sum = y[0][0]; // First term
    for (int i = 1; i < n; i++) {
        sum += (u_cal(u, i) * y[0][i]) / fact(i);
    }

    printf("\nThe interpolated value at x = %.4f is %.4f\n", value, sum);
    return 0;
}
