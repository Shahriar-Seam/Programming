#include <stdio.h>

// Function for calculating number of days it will take the food to reach 1 kg or less
int days(double n)
{
    // Declare variable
    int d;
    
    // Run the loop to divide food amount by 2 and increment value of days
    for (d = 0 ; n >= 1.0; d++) {
        n /= 2.0;
    }

    // Return number of days
    return d;
}

int main()
{
    // Declare variables
    int i, t;
    double food;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Get food quantity
        scanf("%lf", &food);

        // Use days function to calculate and print how many days will it take for the food to reach 1 kg or less
        printf("%d days\n", days(food));
    }

    return 0;
}