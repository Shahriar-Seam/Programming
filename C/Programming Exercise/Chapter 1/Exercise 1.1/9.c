#include <stdio.h>

int main()
{
    double n, w;

    printf("Enter number of apples and average weight (in grams): ");
    scanf("%lf %lf", &n, &w);
    printf("Total weight = %.2lf kg\n", n * w / 1000);

    return 0;
}