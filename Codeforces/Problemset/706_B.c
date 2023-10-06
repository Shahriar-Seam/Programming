#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *) a - *(int *) b);
}

int _count(int *arr, int n, int num)
{
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= num) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low;
}


int main()
{
    int n, q, num, count, i;
    int *arr;

    scanf("%d", &n);

    arr = (int *) malloc(sizeof(int) * n);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    scanf("%d", &q);

    while (q--) {
        scanf("%d", &num);

        if (num >= arr[n - 1]) {
            printf("%d\n", n);

            continue;
        }

        printf("%d\n", _count(arr, n, num));
    }

    free(arr);

    return 0;
}