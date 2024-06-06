#include <stdio.h>

int main()
{
    int a, b, c, base, height;
    double area;

    scanf("%d %d %d", &a, &b, &c);

    if (a > b && a > c) {
        base = b;
        height = c;
    }
    else if (b > a && b > c) {
        base = a;
        height = c;
    }
    else {
        base = a;
        height = b;
    }

    area = (double) base * height * 0.5;

    printf("%lf", area);

    return 0;
}