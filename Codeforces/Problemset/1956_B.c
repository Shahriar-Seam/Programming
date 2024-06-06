#include <stdio.h>
#include <stdlib.h>

void solve()
{
    int n, i, temp, points = 0;

    scanf("%d", &n);

    int *arr = (int *) calloc(n + 1, sizeof(int));

    for (i = 0; i < n; i++) {
        scanf("%d", &temp);

        arr[temp]++;
    }

    for (i = 0; i <= n; i++) {
        if (arr[i] == 2) {
            points++;
        }
    }

    printf("%d\n", points);

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