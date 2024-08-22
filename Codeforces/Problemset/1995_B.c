// pocha code T.T

#include <stdio.h>

typedef struct petal petal;

struct petal {
    long long num;
    long long count;
};

long long max(long long a, long long b)
{
    return a > b ? a : b;
}

void merge_sort(long long *arr, long long *temp, int low, int high)
{
    if (high - low == 1) {
        return;
    }

    int i, j, k, mid;

    mid = low + (high - low) / 2;

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
    long long n, m, sum1, sum2, max_sum = 0;
    int i, j, k, count;

    scanf("%lld %lld", &n, &m);

    long long arr[n], temp[n];

    for (i = 0; i < n; i++) {
        scanf("%lld", arr + i);
    }

    merge_sort(arr, temp, 0, n);

    petal p[n];

    for (i = 0; i < n; i++) {
        p[i].count = 0;
    }

    for (i = 0, j = 0, k = 0; i < n; k++) {
        count = 0;
        j = i;

        while (j < n && arr[i] == arr[j]) {
            count++;
            j++;
        }

        p[k].num = arr[i];
        p[k].count = count;

        i = j;
    }

    for (i = 0; i < k; i++) {
        sum1 = p[i].num * p[i].count;
        
        if (i < k - 1) {
            sum2 = p[i + 1].num * p[i + 1].count;
        }
        else {
            sum2 = 0;
        }

        if (i < k - 1 && p[i].num == p[i + 1].num + 1) {
            if (sum1 + sum2 <= m) {
                max_sum = max(max_sum, sum1 + sum2);
            }
        }
        if (max(sum1, sum2) <= m) {
            max_sum = max(max_sum, max(sum1, sum2));
        }
    }

    printf("%lld\n", max_sum);
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