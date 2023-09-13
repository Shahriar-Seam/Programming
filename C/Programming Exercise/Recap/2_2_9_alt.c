#include <stdio.h>

int main()
{
    double height[5], max = 0;
    int i;

    for (i = 0; i < 5; i++) {
        scanf("%lf", &height[i]);

        if (height[i] > max) {
            max = height[i];
        }
    }

    printf("Max height = %.2lf", max);

    return 0;
}