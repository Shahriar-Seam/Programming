#include <stdio.h>
#include <stdlib.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int compare(const void *a, const void *b)
{
    return (*(int *) a - *(int *) b);
}

int _max(int *arr, int n)
{
    int i, max = arr[0];

    for (i = 1; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    return max;
}

int main()
{
    int t, n, d, i;
    int *arr;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &d);

        arr = (int *) malloc(sizeof(int) * n);

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        if (_max(arr, n) <= d) {
            yes;
            continue;
        }

        qsort(arr, n, sizeof(int), compare);

        if (arr[0] + arr[1] <= d) {
            yes;
        }
        else {
            no;
        }

        free(arr);
    }

    return 0;
}