#include <stdio.h>

void merge_sort(int *num, int *temp, int low, int high)
{
    if (low == high) {
        return;
    }

    int mid = (low + high) / 2;

    merge_sort(num, temp, low, mid);
    merge_sort(num, temp, mid + 1, high);

    int i, j, k;

    // 1st array -> low to mid
    // 2nd array -> mid + 1 to high
    // merging them
    for (i = low, j = mid + 1, k = low; k <= high; ) {
        if (i <= mid && j <= high) {
            if (num[i] < num[j]) {
                temp[k++] = num[i++];
            }
            else {
                temp[k++] = num[j++];
            }
        }
        else if (i <= mid) {
            while (i <= mid) {
                temp[k++] = num[i++];
            }
        }
        else {
            while (j <= high) {
                temp[k++] = num[j++];
            }
        }
    }

    for (k = low; k <= high; k++) {
        num[k] = temp[k];
    }
}

int main()
{
    int n, i, j;

    scanf("%d", &n);

    int num[n], temp[n];

    for (i = 0; i < n; i++) {
        scanf("%d", num + i);
    }

    merge_sort(num, temp, 0, n - 1);

    for (i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }

    return 0;
}