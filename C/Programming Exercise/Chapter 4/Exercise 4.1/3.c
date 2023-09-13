#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;

    scanf("%d", &n);

    double num[n];
    double sum = 0, average, difference = 0, sqr_diff_sum = 0, sigma;

    for (i = 0; i < n; i++) {
        scanf("%lf", &num[i]);
        sum += num[i];
    }

    average = sum / n;

    for (i = 0; i < n; i++) {
        difference = average - num[i];
        sqr_diff_sum += difference * difference;
    }

    sigma = sqrt(sqr_diff_sum / n);

    printf("Average: %g\n", average);
    printf("Standard Deviation: %g\n", sigma);

    return 0;
}