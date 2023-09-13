#include <stdio.h>

int main()
{
    int i, j;
    double temp, height[12];

    for (i = 0; i < 12; i++) {
        scanf("%lf", &height[i]);
    }

    for (j = 11; j > 0; j--) {
        for (i = 0; i < j; i++) {
            if (height[i] > height[i + 1]) {
                temp = height[i];
                height[i] = height[i + 1];
                height[i + 1] = temp;
            }
        }
    }

    printf("Shortest: %g\n2nd Shortest: %g\n", height[0], height[1]);

    return 0;
}