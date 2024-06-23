#include <stdio.h>

void merge_sort(int *arr, int *temp, int l, int r)
{
    if (l == r) {
        return;
    }

    int mid = l + (r - l) / 2;

    merge_sort(arr, temp, l, mid);
    merge_sort(arr, temp, mid + 1, r);

    int i, j, k;

    for (i = l, j = mid + 1, k = l; k <= r; ) {
        if (i <= mid && j <= r) {
            if (arr[i] < arr[j]) {
                temp[k++] = arr[i++];
            }
            else {
                temp[k++] = arr[j++];
            }
        }
        else if (i <= mid) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
        }
    }

    for (k = l; k <= r; k++) {
        arr[k] = temp[k];
    }
}

int main()
{
    int n, i, count = 0;

    scanf("%d", &n);

    int arr[n], temp[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    merge_sort(arr, temp, 0, n - 1);

    for (i = 1; i < n; i++) {
        if (arr[i] <= arr[i - 1]) {
            while (arr[i] <= arr[i - 1]) {
                arr[i]++;
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}