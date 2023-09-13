#include <stdio.h>

int main()
{
    double x, y, m, rohmot, bijoy;

    scanf("%lf %lf %lf", &x, &y, &m);

    rohmot = x / 4;
    bijoy = y / (1000 / m);

    if (rohmot > bijoy) {
        printf("Bijoy.\n");
    }
    else {
        printf("Rohmot.\n");
    }

    return 0;
}