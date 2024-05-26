#include <stdio.h>
#include <stdbool.h>

bool is_sorted(int *arr, int n)
{
    int i;

    for (i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }

    return true;
}

void solve()
{
    int n, i, index = 0, j;

    scanf("%d", &n);

    int arr[n];
    int arr2[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            index = i;

            break;
        }
    }

    for (i = index, j = 0; i < n; i++) {
        arr2[j++] = arr[i];
    }

    for (i = 0, j; i < index; i++) {
        arr2[j++] = arr[i];
    }

    puts(is_sorted(arr2, n) == true ? "YES" : "NO");
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