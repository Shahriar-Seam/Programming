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

void solve()
{
    int n, k, i;
    int sum = 0, count = 0;

    scanf("%d %d", &n, &k);

    int arr[n], temp[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    merge_sort(arr, temp, 0, n);

    for (i = 0; i < n; i++) {
        if (sum + arr[i - 1] <= k) {
            sum += arr[i];
            count += arr[i - 1];
        }
        else {
            count += k - sum;
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