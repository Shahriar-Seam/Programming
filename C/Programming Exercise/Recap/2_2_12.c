#include <stdio.h>

int main()
{
    int arr[4], a, b, c, i, max = -999999999, max_index;

    for (i = 0; i < 4; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < 4; i++) {
        if (arr[i] > max) {
            max = arr[i];
            max_index = i;
        }
    }

    arr[max_index] = 0;

    if (arr[0] == 0) {
        a = arr[1], b = arr[2], c = arr[3];
    }
    if (arr[1] == 0) {
        a = arr[0], b = arr[2], c = arr[3];
    }
    if (arr[2] == 0) {
        a = arr[0], b = arr[1], c = arr[3];
    }
    if (arr[3] == 0) {
        a = arr[0], b = arr[1], c = arr[2];
    }

    if (a < b && a < c) {
        if (b < c) {
            printf("%d %d %d %d", a, b, c, max);
        }
        if (c < b) {
            printf("%d %d %d %d", a, c, b, max);
        }
    }
    if (b < a && b < c) {
        if (a < c) {
            printf("%d %d %d %d", b, a, c, max);
        }
        if (c < a) {
            printf("%d %d %d %d", b, c, a, max);
        }
    }
    if (c < b && c < a) {
        if (a < b) {
            printf("%d %d %d %d", c, a, b, max);
        }
        if (b < a) {
            printf("%d %d %d %d", c, b, a, max);
        }
    }

    return 0;
}