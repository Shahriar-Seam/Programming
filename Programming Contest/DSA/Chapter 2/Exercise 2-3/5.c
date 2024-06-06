#include <stdio.h>

int main()
{
    int x, y;

    scanf("%d %d", &x, &y);

    if (x >= 0 && y >= 0) {
        printf("First\n");
    }
    else if (x <= 0 && y >= 0) {
        printf("Second\n");
    }
    else if (x <= 0 && y <= 0) {
        printf("Third\n");
    }
    else if (x >= 0 && y <= 0) {
        printf("Fourth\n");
    }

    if (x == 0) {
        printf("On Y axis\n");
    }
    else if (y == 0) {
        printf("On X axis\n");
    }
    else if (x == 0 && y == 0) {
        printf("Origin\n");
    }

    return 0;
}