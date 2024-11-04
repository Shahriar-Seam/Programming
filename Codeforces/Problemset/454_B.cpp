#include <stdio.h>

void merge_sort(int *arr, int *temp, int l, int r)
{
    int mid = (l + r) / 2;

    if (r - l == 1) {
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

int main()
{
    int n, i, j, start = 0, f = 1;

    scanf("%d", &n);

    int arr[n], sorted_arr[n], temp[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);

        sorted_arr[i] = arr[i];
    }

    merge_sort(sorted_arr, temp, 0, n);

    for (i = 0; i < n; i++) {
        if (sorted_arr[0] == arr[i]) {
            start = i;
        }
    }

    for (i = start, j = 0; i < n; i++, j++) {
        if (arr[i] != sorted_arr[j]) {
            f = 0;

            break;
        }
    }

    for (i = 0, j; i < start; i++, j++) {
        if (arr[i] != sorted_arr[j]) {
            f = 0;

            break;
        }
    }
    
    if (sorted_arr[0] == sorted_arr[n - 1]) {
        start = 0;
    }

    printf("%d\n", (f ? (n - start) % n : -1));

    return 0;
}