#include <stdio.h>
#include <math.h>

int main()
{
    int num[10], difference, difference_sum = 0, i;
    double avg = 0;

    for (i = 0; i < 10; i++) {
        scanf("%d", &num[i]);
    }

    for (i = 0; i < 9; i++) {
        difference = abs(num[i+1] - num[i]);
        difference_sum += difference;
        printf("%d ", difference);
    }

    printf("\n");

    avg = (double) difference_sum / 9;
    printf("Average of difference: %g\n", avg);

    return 0;
}