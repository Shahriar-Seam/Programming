#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *arr, int *temp, int low, int high)
{
    if (low == high) {
        return;
    }

    int mid = low + (high - low) / 2;
    int i, j, k;

    merge_sort(arr, temp, low, mid);
    merge_sort(arr, temp, mid + 1, high);

    for (i = low, j = mid + 1, k = low; k <= high; k++) {
        if (i <= mid && j <= high) {
            if (arr[i] < arr[j]) {
                temp[k] = arr[i++];
            }
            else {
                temp[k] = arr[j++];
            }
        }
        else if (i <= mid) {
            temp[k] = arr[i++];
        }
        else {
            temp[k] = arr[j++];
        }
    }

    for (k = low; k <= high; k++) {
        arr[k] = temp[k];
    }
}

void solve()
{
    int n, i, count = 1;
    int *arr, *temp;

    scanf("%d", &n);

    arr = (int *) malloc(sizeof(int) * n);
    temp = (int *) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    merge_sort(arr, temp, 0, n - 1);

    for (i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            count++;
        }
    }

    printf("%d\n", count);
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}