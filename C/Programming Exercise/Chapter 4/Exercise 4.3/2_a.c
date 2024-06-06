#include <stdio.h>
#include <math.h>

int main()
{
    double points[5][2], distance;
    int i, j;

    // Input points
    for (i = 0; i < 5; i++) {
        scanf("%lf %lf", &points[i][0], &points[i][1]);
    }

    // Calculate and print distance
    printf("\nPoints:\t\t\tDistance\n");
    for (i = 0; i < 5; i++) {
        for (j = i + 1; j < 5; j++) {
            distance = sqrt(pow((points[i][0] - points[j][0]), 2) + pow((points[i][1] - points[j][1]), 2));
            printf("(%g, %g) & (%g, %g):\t%g\n", points[i][0], points[i][1], points[j][0], points[j][1], distance);
        }
    }

    return 0;
}