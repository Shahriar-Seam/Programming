#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_sorted(int *arr, int n)
{
    int i;

    for (i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            return false;
        }
    }

    return true;
}

void solve()
{
    int n, i, j;
    
    scanf("%d", &n);

    int *arr = (int *) malloc(sizeof(int) * n);
    int *arr2 = (int *) malloc(sizeof(int) * 2 * n);

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    arr2[0] = arr[n - 1];

    for (i = n - 2, j = 0; i >= 0; i--) {
        if (arr[i] > arr2[j]) {
            arr2[++j] = arr[i] % 10;
            arr2[++j] = arr[i] / 10;
        }
        else {
            arr2[++j] = arr[i];
        }
    }

    puts(is_sorted(arr2, j + 1) == true ? "YES" : "NO");

    free(arr);
    free(arr2);
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