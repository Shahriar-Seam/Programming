#include <stdio.h>

int main()
{
    double a, b, c, d, e;

    scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);

    if (a > b && a > c && a > d && a > e) {
        printf("Tallest: %.2lf", a);
    }
    if (b > a && b > c && b > d && b > e) {
        printf("Tallest: %.2lf", b);
    }
    if (c > a && c > b && c > d && c > e) {
        printf("Tallest: %.2lf", c);
    }
    if (d > b && d > c && d > a && d > e) {
        printf("Tallest: %.2lf", d);
    }
    if (e > b && e > c && e > d && e > a) {
        printf("Tallest: %.2lf", e);
    }

    return 0;
}