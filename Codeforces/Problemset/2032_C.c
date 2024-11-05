#include <stdio.h>
#include <limits.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

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

int binary_search(int *arr, int start, int n, int k)
{
    int l = start, r = n - 1, mid, index = 0;

    while (l <= r) {
        mid = (l + r) / 2;

        if (arr[mid] < k) {
            index = mid;

            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    return index;
}

void solve()
{
    int n, i, ops = INT_MAX;

    scanf("%d", &n);

    int arr[n], temp[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    merge_sort(arr, temp, 0, n);

    for (i = 0; i < n - 1; i++) {
        ops = min(ops, i + n - binary_search(arr, i, n, arr[i] + arr[i + 1]) - 1);
    }

    printf("%d\n", ops);
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