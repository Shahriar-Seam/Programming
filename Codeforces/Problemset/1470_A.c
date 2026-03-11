#include <stdio.h>
#include <stdint.h>

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

void solve()
{
    int n, m, i, j;
    long long cost = 0;

    scanf("%d %d", &n, &m);

    int k[n], temp[n], c[m];

    for (i = 0; i < n; i++) {
        scanf("%d", k + i);
    }

    for (i = 0; i < m; i++) {
        scanf("%d", c + i);
    }

    merge_sort(k, temp, 0, n);

    for (i = n - 1, j = 0; i >= 0; i--) {
        if (c[k[i] - 1] > c[j]) {
            cost += c[j++];
        }
        else {
            cost += c[k[i] - 1];
        }
    }

    printf("%lld\n", cost);
}

int32_t main()
{
    int32_t t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}