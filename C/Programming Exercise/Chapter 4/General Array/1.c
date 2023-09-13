#include <stdio.h>
#include <math.h>

int main()
{
    double numbers[10], sum = 0, mean = 0, sqr_diff_sum = 0, sigma = 0;
    int i;

    for (i = 0; i < 10; i++) {
        scanf("%lf", &numbers[i]);
    }

    for (i = 0; i < 10; i++) {
        sum += numbers[i];
    }

    mean = sum / 10;
    printf("Mean: %g\n", mean);

    for (i = 0; i < 10; i++) {
        double difference = mean - numbers[i];
        sqr_diff_sum += difference * difference;
    }

    sigma = sqrt(sqr_diff_sum / 10);
    printf("Standard Deviation: %g\n", sigma);

    return 0;
}