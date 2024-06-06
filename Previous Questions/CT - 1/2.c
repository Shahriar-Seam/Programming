#include <stdio.h>
#include <math.h>

int main()
{
    float n, d;

    scanf("%f", &n);

    d = n - (int) n;

    if (d > 0.799999) {
        printf("%0.0lf\n", ceil(n));
    }
    else {
        printf("%d\n", (int) n);
    }

    return 0;
}