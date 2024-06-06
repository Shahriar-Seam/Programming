#include <stdio.h>
#include <math.h>

int main()
{
    int t;
    double a, b;

    scanf("%d", &t);

    while (t--) {
        scanf("%lf %lf", &a, &b);

        printf("%d\n", (int) ceil(a * b / 2.0));
    }

    return 0;
}