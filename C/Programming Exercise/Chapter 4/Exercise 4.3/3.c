#include <stdio.h>
#include <math.h>

int main()
{
    double x, y, r, points[10][2], distance[10];
    int i, count = 0;

    // Input center and radius
    printf("Enter coordinate of the circles center: ");
    scanf("%lf %lf", &x, &y);
    printf("Enter radius of the circle: ");
    scanf("%lf", &r);

    // Input points
    printf("Enter coordinates of the points:\n");
    for (i = 0; i < 10; i++) {
        scanf("%lf %lf", &points[i][0], &points[i][1]);
    }

    // Measure distance from center and store
    for (i = 0; i < 10; i++) {
        distance[i] = sqrt(pow((x - points[i][0]), 2) + pow((y - points[i][1]), 2));
    }

    // Compare distance with radius
    printf("\nPoints inside the circle are:\n");
    for (i = 0; i < 10; i++) {
        if (distance[i] < r) {
            printf("(%g, %g)\n", points[i][0], points[i][1]);
            count++;
        }
    }

    // Print number of points inside circle
    printf("Total points inside the circle is: %d\n", count);

    return 0;
}