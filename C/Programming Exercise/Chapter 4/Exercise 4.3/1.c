#include <stdio.h>

int main()
{
    double size_and_price[10][2], price_per_inch[10], sum = 0, average;
    int i;

    for (i = 0; i < 10; i++) {
        scanf("%lf %lf", &size_and_price[i][0], &size_and_price[i][1]);
    }

    for (i = 0; i < 10; i++) {
        price_per_inch[i] = size_and_price[i][0] / size_and_price[i][1];
        sum += price_per_inch[i];
    }

    average = sum / 10.0;

    printf("%g\n", average);

    return 0;
}