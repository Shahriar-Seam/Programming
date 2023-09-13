#include <stdio.h>

int main()
{
    int n;
    double num, sum = 0, average;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%lf", &num);

        sum = sum + num;
    }

    average = sum / n;

    printf("Average = %.2lf", average);

    return 0;
}