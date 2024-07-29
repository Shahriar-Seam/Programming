#include <stdio.h>

void merge_sort(int *arr, int *temp, int l, int r)
{
    if (l == r) {
        return;
    }

    int mid = l + (r - l) / 2;

    merge_sort(arr, temp, l, mid);
    merge_sort(arr, temp, mid + 1, r);

    int i, j, k;

    for (i = l, j = mid + 1, k = l; k <= r; ) {
        if (i <= mid && j <= r) {
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

    for (k = l; k <= r; k++) {
        arr[k] = temp[k];
    }
}

void solve()
{
    int n, i, j, k, mid;

    scanf("%d", &n);

    int arr[n], temp[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    merge_sort(arr, temp, 0, n - 1);
    
    mid = (n - 1) / 2;

    temp[0] = arr[mid];

    for (j = 1, k = 1; j <= mid; j++) {
        if (mid + j < n) {
            temp[k++] = arr[mid + j];
        }
        if (mid - j >= 0) {
            temp[k++] = arr[mid - j];
        }
    }

    for (i = 0; i < n; i++) {
        printf("%d ", temp[i]);
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