#include <stdio.h>
#include <math.h>

int main()
{
    int x = 1, y;

    for (x; x <= 100; x++) {
        y = pow(x, 2);
        printf("%d\n", y);
    }

    return 0;
}