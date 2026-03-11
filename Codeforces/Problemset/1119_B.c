#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

void merge_sort(int *arr,  int *temp, int l, int r)
{
    int mid = (l + r) / 2;

    if (r - l <= 1) {
        return;
    }

    merge_sort(arr, temp, l, mid);
    merge_sort(arr, temp, mid, r);

    int i, j, k;

    for (i = l, j = mid, k = l; k < r; k++) {
        temp[k] = (i < mid && j < r) ? (arr[i] < arr[j] ? arr[i++] : arr[j++]) : (i < mid ? arr[i++] : arr[j++]);
    }

    for (k = l; k < r; k++) {
        arr[k] = temp[k];
    }
}

void copy(int *arr, int *arr2, int n)
{
    if (n > 0) {
        memcpy(arr2, arr, n * sizeof(int));
    }
}

bool possible(int *arr, int *arr2, int *temp, int m, int h)
{
    int i;
    long long sum = 0;

    copy(arr, arr2, m);

    merge_sort(arr2, temp, 0, m);
    
    for (i = m - 1; i >= 0; i -= 2) {
        sum += arr2[i];
    }

    return sum <= h;
}

int32_t main()
{
    int n, h, i, k = 0;
    int l, r, m;

    scanf("%d %d", &n, &h);

    int arr[n], temp[n], arr2[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    l = 0, r = n;

    while (l <= r) {
        m = (l + r) / 2;

        if (possible(arr, arr2, temp, m, h)) {
            k = m;

            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    printf("%d\n", k);

    return 0;
}