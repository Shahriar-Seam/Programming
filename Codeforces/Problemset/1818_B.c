#include <stdio.h>

int main()
{
    int t, n, i;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        if (n % 2 == 1 && n > 1) {
            puts("-1");

            continue;
        }

        if (n == 1) {
            puts("1");
            
            continue;
        }

        for (i = 1; i < n; i += 2) {
            printf("%d %d ", i + 1, i);
        }

        puts("");
    }

    return 0;
}