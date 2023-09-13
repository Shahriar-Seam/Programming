#include <stdio.h>

int main()
{
    double n, sum = 0, average;

    for(int i = 1; i <= 10; i++) {
        scanf("%lf", &n);
        sum = sum + n;
    }

    average = sum / 10;
    printf("%.2lf", average);

    return 0;
}