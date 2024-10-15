#include <stdio.h>

void merge_sort(int *arr, int *temp, int low, int high)
{
    if (high - low == 1) {
        return;
    }

    int i, j, k, mid = (low + high) / 2;

    merge_sort(arr, temp, low, mid);
    merge_sort(arr, temp, mid, high);

    for (i = low, j = mid, k = low; k < high; k++) {
        temp[k] = (i < mid && j < high) ? (arr[i] > arr[j] ? arr[i++] : arr[j++]) : (i < mid ? arr[i++] : arr[j++]);
    }

    for (k = low; k < high; k++) {
        arr[k] = temp[k];
    }
}

void solve()
{
    int n, i;
    long long bob = 0, alice = 0;

    scanf("%d", &n);

    int arr[n], temp[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    merge_sort(arr, temp, 0, n);

    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (arr[i] % 2 == 0) {
                alice += 1LL * arr[i];
            }
        }
        else {
            if (arr[i] % 2 == 1) {
                bob += 1LL * arr[i];
            }
        }
    }

    puts((alice > bob) ? ("Alice") : (alice == bob ? "Tie" : "Bob"));
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