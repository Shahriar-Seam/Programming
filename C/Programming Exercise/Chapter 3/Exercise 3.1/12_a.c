#include <stdio.h>

int main()
{
    int n;
    double b, h, a;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter base and height of the triangle:\n");
        scanf("%lf %lf", &b, &h);

        a = b * h / 2;

        printf("The area of the triangle is: %.2lf\n", a);
    }

    return 0;
}