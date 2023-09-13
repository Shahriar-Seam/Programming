#include <stdio.h>
#include <math.h>

int main()
{
    int points[6][2], idx1, idx2;
    int i, j;
    double distance, min_distance = 1e20, x, y;

    for (i = 0; i < 6; i++) {
        scanf("%d %d", &points[i][0], &points[i][1]);
    }

    for (i = 0; i < 5; i++) {
        for (j = i + 1; j < 6; j++) {
            x = pow(points[i][0] - points[j][0], 2);
            y = pow(points[i][1] - points[j][1], 2);
            distance = sqrt(x + y);

            if (distance < min_distance) {
                min_distance = distance;
                idx1 = i;
                idx2 = j;
            }
        }
    }

    printf("Minimum Distance: %g\n", min_distance);
    printf("Point 1: (%d, %d)\n", points[idx1][0], points[idx1][1]);
    printf("Point 2: (%d, %d)\n", points[idx2][0], points[idx2][1]);

    return 0;
}