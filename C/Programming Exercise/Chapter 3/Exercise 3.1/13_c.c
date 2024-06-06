#include <stdio.h>
#include <math.h>

int main()
{
    double x = 1, y;

    for (x; x <= 100; x++) {
        y = (x * x * x) - (x * x * 0.3157894736842105) + (x * 0.5915492957746479) - (0.3703592514760332);
        printf("%.2lf\n", y);
    }

    return 0;
}

// Division is more prone to rounding errors. It's a problem with c.
// C is not suitable for complex mathematical operations.