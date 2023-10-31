#include <stdio.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int main()
{
    int t, n, m, k, x, y;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d", &n, &m, &k);

        int mn = m * n - 1;

        if (mn == k) {
            yes;
        }
        else {
            no;
        }
    }

    return 0;
}