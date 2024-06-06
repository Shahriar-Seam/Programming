#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    double a, area;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter the length of a side of the square:\n");
        scanf("%lf", &a);

        area = pow(a, 2);

        printf("The area of the square is: %.2lf\n", area);
    }

    return 0;
}