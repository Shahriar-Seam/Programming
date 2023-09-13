#include <stdio.h>
#include <math.h>

int main()
{
    double principle[3] = {10000, 12000, 15000};
    double c_principle[3] = {0};
    double interest_rate[3] = {6 / 100.0, 5.75 / 100.0, 5.25 / 100.0};
    int i, j, n = 15;

    printf("Jisan\tSami\tJami\n");

    for (i = 1; i <= n; i++) {
        for (j = 0; j < 3; j++) {
            c_principle[j] = principle[j] * pow((1 + interest_rate[j]), i);
            printf("%g\t", c_principle[j]);
        }

        printf("\n");
    }

    return 0;
}