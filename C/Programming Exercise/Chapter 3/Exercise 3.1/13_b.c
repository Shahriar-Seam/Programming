#include <stdio.h>
#include <math.h>

int main()
{
    int x = 1;
    double y;

    for (x; x <= 100; x++) {
        y = pow(x, 2) * log(pow(x, 3));
        printf("%.2lf\n", y);
    }

    return 0;
}