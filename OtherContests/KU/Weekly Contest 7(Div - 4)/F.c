#include <stdio.h>
#include <stdint.h>

int32_t main()
{
    int n, k, i, x, count = 0, luck;

    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++) {
        scanf("%d", &x);

        luck = 0;

        while (x > 0) {
            if (x % 10 == 4 || x % 10 == 7) {
                luck++;
            }
            
            x /= 10;
        }

        if (luck <= k) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}