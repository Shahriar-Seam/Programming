#include <stdio.h>

void solve()
{
    int n, a, b, i, j = 0;

    scanf("%d %d %d", &n, &a, &b);

    for (i = 0; i < n; i++) {
        if (i % b == 0) {
            j = 0;
        }

        printf("%c", 'a' + j++);
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