#include <stdio.h>

typedef struct {
    int start, end;
} movie;

void merge_sort(movie *arr, movie *temp, int l, int r)
{
    int mid = (l + r) / 2;

    if (r - l == 1) {
        return;
    }

    merge_sort(arr, temp, l, mid);
    merge_sort(arr, temp, mid, r);

    int i, j, k;

    for (i = l, j = mid, k = l; k < r; k++) {
        temp[k] = (i < mid && j < r) ? (arr[i].end < arr[j].end ? arr[i++] : arr[j++]) : (i < mid ? arr[i++] : arr[j++]);
    }

    for (k = l; k < r; k++) {
        arr[k] = temp[k];
    }
}

int main()
{
    int n, i, ending = 0, count = 0;

    scanf("%d", &n);

    movie m[n], temp[n];

    for (i = 0; i < n; i++) {
        scanf("%d %d", &m[i].start, &m[i].end);
    }

    merge_sort(m, temp, 0, n);

    for (i = 0; i < n; i++) {
        if (ending <= m[i].start) {
            ending = m[i].end;

            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}