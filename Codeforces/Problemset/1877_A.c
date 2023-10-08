#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, n, i, eff = 0, num;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        eff = 0;

        for (i = 1; i < n; i++) {
            scanf("%d", &num);

            eff += num;
        }

        printf("%d\n", -eff);
    }

    return 0;
}