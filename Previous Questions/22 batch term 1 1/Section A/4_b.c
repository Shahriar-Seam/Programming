#include <stdio.h>

int main()
{
    double x, sum, t, d;
    int i, n;

    scanf("%lf", &x);
    scanf("%d", &n);

    sum = 1;
    t = 1;

    for (i = 1; i < n; i++) {
        d = (2 * i) * (2 * i - 1);
        t = -t * x * x / d;
        sum = sum + t;
    }
    printf("\nthe sum = %g\nNumber of terms = %d\nvalue of x = %g\n", sum, n, x);
}
