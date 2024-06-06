#include <stdio.h>

int main()
{
    double a1, a2, b1, b2, c1, c2, d, x, y;
    
    printf("Equation Solver\n");
    printf("a1x + b1y = c1 \t&\na2x + b2y = c2\n");
    printf("Enter values of a1, b1, c1 respectively: ");
    scanf("%lf %lf %lf", &a1, &b1, &c1);
    printf("Enter values of a2, b2, c2 respectively: ");
    scanf("%lf %lf %lf", &a2, &b2, &c2);

    d = a1 * b2 - a2 * b1;
    if ((int) d == 0) {
        printf("Value of x and y cannot be determined.\n");
    }
    else {
        x = (b2 * c1 - b1 * c2) / d;
        y = (a1 * c2 - a2 * c1) / d;

        printf("x = %.2lf\ny = %.2lf\n", x, y);
    }

    return 0;
}