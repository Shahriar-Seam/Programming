#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, temp, d, min;
    int dist[100];
    int i;

    scanf("%d %d %d", &a, &b, &c);

    for (i = 1; i <= 100; i++) {
        dist[i - 1] = abs(i - a) + abs(i - b) + abs(i - c);
    }

    min = dist[0];

    for (i = 1; i < 100; i++) {
        if (dist[i] < min) {
            min = dist[i];
        }
    }

    printf("%d", min);

    return 0;
}