#include <stdio.h>

void merge_sort(int *arr, int *temp, int low, int high)
{
    if (low == high) {
        return;
    }

    int mid = low + (high - low) / 2;

    merge_sort(arr, temp, low, mid);
    merge_sort(arr, temp, mid + 1, high);

    int i, j, k;

    for (i = low, j = mid + 1, k = low; k <= high; ) {
        if (i <= mid && j <= high) {
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

    for (i = low; i <= high; i++) {
        arr[i] = temp[i];
    }
}

void solve()
{
    int n, i, f = 1, o = 0;

    scanf("%d", &n);

    int arr[n], temp[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);

        o += (arr[i] == 1);
    }

    merge_sort(arr, temp, 0, n - 1);

    if (o > 0) {
        for (i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] == 1) {
                f = 0;
            }
        }
    }

    puts(f == 1 ? "YES" : "NO");
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