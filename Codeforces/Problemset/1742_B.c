#include <stdio.h>
#include <stdlib.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int compare(const void *a, const void *b)
{
    return (* (int *) a - * (int *) b);
}

int main()
{
    int t, n, f, i;
    int *arr;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        arr = (int *) malloc(sizeof(int) * n);
        f = 1;

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        qsort(arr, n, sizeof(int), compare);

        for (i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] == 0) {
                f = 0;
                break;
            }
        }

        f ? yes : no;
    }

    return 0;
}