#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *arr, int *temp, int low, int high)
{
    int mid = low + (high - low) / 2;
    int i, j, k;

    if (high - low == 1) {
        return;
    }

    merge_sort(arr, temp, low, mid);
    merge_sort(arr, temp, mid, high);

    for (i = low, j = mid, k = low; k < high; k++) {
        if (i < mid && j < high) {
            temp[k] = (arr[i] < arr[j] ? arr[i++] : arr[j++]);
        }
        else {
            temp[k] = (i < mid ? arr[i++] : arr[j++]);
        }
    }

    for (k = low; k < high; k++) {
        arr[k] = temp[k];
    }
}

void solve()
{
    int n, i, odd = 0, ops_count = 0, x;
    int ops[40] = {};

    scanf("%d", &n);

    int arr[n], temp[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);

        odd += (arr[i] % 2);
    }

    if (odd > 0 && odd < n) {
        printf("-1\n");

        return;
    }

    merge_sort(arr, temp, 0, n);

    while (arr[n - 1] != 0) {
        x = ops[ops_count++] = (arr[0] + arr[n - 1]) / 2;

        for (i = 0; i < n; i++) {
            arr[i] = abs(arr[i] - x);
        }

        merge_sort(arr, temp, 0, n);
    }

    printf("%d\n", ops_count);

    for (i = 0; i < ops_count; i++) {
        printf("%d ", ops[i]);
    }

    printf("\n");
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