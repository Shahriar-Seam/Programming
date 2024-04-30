#include <stdio.h>

void solve()
{
    int n, i, temp, polygons = 0;
    int counter[101] = {};

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &temp);

        counter[temp]++;
    }

    for (i = 0; i < 101; i++) {
        polygons += counter[i] / 3;
    }

    printf("%d\n", polygons);
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