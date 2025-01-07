#include <stdio.h>

void merge_sort(int *first, int *last, int *temp)
{
    if (last - first == 1) {
        return;
    }

    int i, j, k, m;

    m = (last - first) / 2;

    merge_sort(first, first + m, temp);
    merge_sort(first + m, last, temp);

    for (i = 0, j = m, k = 0; first + k < last; k++) {
        temp[k] = (i < m && first + j < last) ? (first[i] < first[j] ? first[i++] : first[j++]) : (i < m ? first[i++] : first[j++]);
    }

    for (k = 0; first + k < last; k++) {
        first[k] = temp[k];
    }
}

int main()
{
    int n, i, j, sorted = 1;

    scanf("%d", &n);

    int arr[n], temp[n];
    char s[n + 1];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    scanf(" %s", s);

    for (i = 0; i < n - 1; ) {
        if (s[i] == '1') {
            j = i;

            while (s[j++] == '1');

            merge_sort(arr + i, arr + j, temp);

            i = j;
        }
        else {
            i++;
        }
    }

    for (i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            sorted = 0;

            break;
        }
    }

    puts(sorted ? "YES" : "NO");

    return 0;
}