#include <stdio.h>
#include <stdlib.h>

void solve()
{
    int n, i, temp, operations = 0;

    scanf("%d", &n);

    int *arr = (int *) calloc(n + 1, sizeof(int));

    for (i = 1; i <= n; i++) {
        scanf("%d", &temp);

        arr[temp] = i;
    }

    for (i = 1; i < n; i++) {
        if (arr[i] > arr[i + 1]) {
            operations++;
        }
    }

    printf("%d\n", operations);

    free(arr);
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