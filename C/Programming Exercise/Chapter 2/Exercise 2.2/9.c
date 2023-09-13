#include <stdio.h>

int main()
{
    double a, b, c, d, e;

    scanf("%lf %lf %lf %lf %lf", &a, &b, &c, &d, &e);

    if (a > b && a > c && a > d && a > e) {
        printf("Tallest: %.2lf m\n", a);
    }
    if (b > a && b > c && b > d && b > e) {
        printf("Tallest: %.2lf m\n", b);
    }
    if (c > a && c > b && c > d && c > e) {
        printf("Tallest: %.2lf m\n", c);
    }
    if (d > a && d > b && d > c && d > e) {
        printf("Tallest: %.2lf m\n", d);
    }
    if (e > a && e > b && e > c && e > d) {
        printf("Tallest: %.2lf m\n", e);
    }

    return 0;
}