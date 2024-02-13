#include <stdio.h>

void solve()
{
    int n, temp;

    scanf("%d", &n);

    printf("1 %d\n", n);

    while (n--) {
        scanf("%d", &temp);
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