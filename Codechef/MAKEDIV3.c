#include <stdio.h>

void solve()
{
    int n;

    scanf("%d", &n);

    if (n == 1) {
        printf("3\n");
    }
    else {
        n -= 2;

        printf("1");

        while (n--) {
            printf("0");
        }

        printf("5\n");
    }
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