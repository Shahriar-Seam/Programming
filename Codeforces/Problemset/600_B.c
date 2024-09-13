#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *arr, int *temp, int low, int high)
{
    if (high - low == 1) {
        return;
    }

    int i, j, k, mid;

    mid = low + (high - low) / 2;

    merge_sort(arr, temp, low, mid);
    merge_sort(arr, temp, mid, high);

    for (i = low, j = mid, k = low; k < high; k++) {
        temp[k] = (i < mid && j < high) ? (arr[i] < arr[j] ? arr[i++] : arr[j++]) : (i < mid ? arr[i++] : arr[j++]);
    }

    for (k = low; k < high; k++) {
        arr[k] = temp[k];
    }
}

int less_eq(int *arr, int b, int n)
{
    int l = 0, r = n - 1, m;

    while (l <= r) {
        m = l + (r - l) / 2;

        if (arr[m] <= b) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    return l;
}

int main()
{
    int n, m, i;

    scanf("%d %d", &n, &m);

    int arr[n], temp[n], b;

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    merge_sort(arr, temp, 0, n);

    while (m--) {
        scanf("%d", &b);

        printf("%d ", less_eq(arr, b, n));
    }

    return 0;
}