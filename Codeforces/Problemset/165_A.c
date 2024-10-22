#include <stdio.h>

typedef struct {
    int x, y;
} pair;

int right(pair *arr, pair p, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        if (arr[i].y == p.y && arr[i].x > p.x) {
            return 1;
        }
    }

    return 0;
}

int left(pair *arr, pair p, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        if (arr[i].y == p.y && arr[i].x < p.x) {
            return 1;
        }
    }

    return 0;
}

int higher(pair *arr, pair p, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        if (arr[i].x == p.x && arr[i].y > p.y) {
            return 1;
        }
    }

    return 0;
}

int lower(pair *arr, pair p, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        if (arr[i].x == p.x && arr[i].y < p.y) {
            return 1;
        }
    }

    return 0;
}

int main()
{
    int n, i, count = 0;

    scanf("%d", &n);

    pair arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }

    for (i = 0; i < n; i++) {
        count += (right(arr, arr[i], n) && left(arr, arr[i], n) && higher(arr, arr[i], n) && lower(arr, arr[i], n));
    }

    printf("%d\n", count);

    return 0;
}