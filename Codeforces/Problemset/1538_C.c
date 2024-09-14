#include <stdio.h>

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
    int n, l, r, i;
    int left, right;
    long long ll = 0, rr = 0;

    scanf("%d %d %d", &n, &l, &r);

    int arr[n], temp[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    merge_sort(arr, temp, 0, n);

    left = 0;
    right = n - 1;

    while (left < right) {
        if (arr[left] + arr[right] <= r) {
            rr += 1LL * right - left;
            left++;
        }
        else {
            right--;
        }
    }

    left = 0;
    right = n - 1;

    while (left < right) {
        if (arr[left] + arr[right] < l) {
            ll += 1LL * right - left;
            left++;
        }
        else {
            right--;
        }
    }

    printf("%lld\n", rr - ll);
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