#include <stdio.h>
#include <math.h>

int main()
{
    // Declare variables
    int i, t;
    double x, y, x1, y1, r, l;

    // Scan number of test cases
    scanf("%d", &t);

    // Run loop for all test cases
    for (i = 0; i < t; i++) {
        // Take the inputs
        scanf("%lf %lf", &x, &y); // Centre
        scanf("%lf", &r); // Radius
        scanf("%lf %lf", &x1, &y1); // Coordinate of the point

        // Find the distance of the point from the centre of the circle
        l = sqrt(pow((x - x1), 2) + pow((y - y1), 2));

        if (l > r) {
            printf("The point is not inside the circle\n");
        }
        else {
            printf("The point is inside the circle\n");
        }
    }

    return 0;
}