#include <stdio.h>
#include <math.h>

int main()
{
    double principles[3] = {10000, 12000, 15000};
    int i, j;
    double rate_of_interest, c;

    printf("Enter rate of interest: ");
    scanf("%lf", &rate_of_interest);
    rate_of_interest /= 100.0;

    printf("\nName:\t\tJisan\t\tSami\t\tJami\n");

    for (i = 1; i <= 15; i++) {
        printf("Year %2d:\t", i);

        for (j = 0; j < 3; j++) {
            c = principles[j] * pow((1 + rate_of_interest), i);
            printf("%g\t\t", c);
        }

        printf("\n");
    }

    return 0;
}