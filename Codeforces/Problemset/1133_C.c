#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *arr, int *temp, int low, int high)
{
    if (low == high) {
        return;
    }

    int mid = (low + high) / 2;

    // split
    merge_sort(arr, temp, low, mid);
    merge_sort(arr, temp, mid + 1, high);

    int i, j, k;

    // first array -> low to mid
    // second array -> mid + 1 to high
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
            while (i <= mid) {
                temp[k++] = arr[i++];
            }
        } // 2nd array emptied
        else {
            while (j <= high) {
                temp[k++] = arr[j++];
            }
        } // 1st array emptied
    }

    for (k = low; k <= high; k++) {
        arr[k] = temp[k];
    }
}

int max(int a, int b)
{
  return a > b ? a : b;
}

int main()
{
    int n, i, l, r, count = 0;

    scanf("%d", &n);

    int arr[n], temp[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    merge_sort(arr, temp, 0, n - 1);

    for (l = 0, r = 0; l < n; l++) {
        while (r < n && arr[r] - arr[l] <= 5) {
            r++;
        }

        count = max(count, r - l);
    }
    
    count = max(count, r - l);

    printf("%d\n", count);

    return 0;
}