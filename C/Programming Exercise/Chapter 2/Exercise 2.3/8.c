#include <stdio.h>

int main()
{
    double x, y, m, rohmot_hali, bijoy_kg;

    scanf("%lf %lf %lf", &x, &y, &m);

    rohmot_hali = x / 4;
    bijoy_kg = y / (1000 / m);

    if (rohmot_hali > bijoy_kg) {
        printf("Bijoy er gula kom dam.\n");
    }
    else {
        printf("Rohmot er gula kom dam.\n");
    }
}