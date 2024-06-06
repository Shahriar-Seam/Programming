#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (* (int *) a - * (int *) b);
}

int main()
{
    int t, n, x, *arr, h, i;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &x);

        arr = (int *) malloc(sizeof(int) * n);

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        qsort(arr, n, sizeof(int), compare);

        int min = arr[0];
        h = min + 1;

        unsigned long long int sum = 0;

        while (sum < x) {
            sum = 0;

            for (i = 0; i < n; i++) {
                if (arr[i] < h) {
                    sum += (unsigned long long int) arr[i] - min;
                }
                else {
                    sum += h - i;
                }
            }

            h++;
        }

        printf("%d\n", h);
    }

    return 0;
}