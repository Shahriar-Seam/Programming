#include <stdio.h>
#include <stdint.h>

#define int long long
const int mod = 1e9 + 7;

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int binary_exponentiation(int b, int p)
{
    int result = 1;

    while (p > 0) {
        if (p & 1) {
            result = (result * b) % mod;
        }

        b = (b * b) % mod;

        p >>= 1;
    }

    return result;
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

int32_t main()
{
    int n, x, i, j, sum = 0;
    int count = 0;

    scanf("%lld %lld", &n, &x);

    int arr[n], diff[n], temp_arr[n], counter[n];

    for (i = 0; i < n; i++) {
        scanf("%lld", arr + i);

        sum += arr[i];

        counter[i] = 0;
    }

    for (i = 0; i < n; i++) {
        diff[i] = sum - arr[i];
    }

    merge_sort(diff, temp_arr, 0, n);

    for (i = 1, count = 1; i < n; i++) {
        if (diff[i] != diff[i - 1]) {
            counter[]
        }
    }

    return 0;
}