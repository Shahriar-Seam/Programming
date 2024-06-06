#include <stdio.h>
#include <math.h>

// Function for calculating area of a triangle using its sides
double calculate_area(int a, int b, int c)
{
    // s = semi perimeter
    double s = (double) (a + b + c) / 2; 

    // Use formula to calculate area of triangle
    double area = sqrt(s * (s - a) * (s - b) * (s - c));

    return area;
}

int main()
{
    // Declare variables
    int i, t, a, b, c;
    double area;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Scan the length of the sides
        scanf("%d %d %d", &a, &b, &c);

        // Use the function to calculate area
        area = calculate_area(a, b, c);

        // Print area
        printf("Area = %0.3lf\n", area);
    }

    return 0;
}