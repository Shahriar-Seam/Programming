#include <stdio.h>

int main()
{
    int n;
    double a, b, s;

    scanf("%d %lf %lf", &n, &a, &b);

    s = a * b;

    printf("NUMBER = %d\n", n);
    printf("SALARY = U$ %0.2lf\n", s);

    return 0;
}