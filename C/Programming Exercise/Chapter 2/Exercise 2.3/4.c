#include <stdio.h>

int main()
{
    int cow, goat;

    scanf("%d %d", &cow, &goat);

    if (cow < goat * 5) {
        printf("Jitsen\n");
    }
    else {
        printf("Thoksen\n");
    }

    return 0;
}