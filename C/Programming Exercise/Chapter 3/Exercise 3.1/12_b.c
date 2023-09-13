#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    double r, a;
    double pi = acos(-1);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter the radius of the circle:\n");
        scanf("%lf", &r);

        a = pi * pow(r, 2);

        printf("The area of the circle is: %.2lf\n", a);
    }

    return 0;
}