#include <stdio.h>
#include <stdint.h>

int32_t main()
{
    int n, m, mod = 1;

    scanf("%d %d", &n, &m);

    while (n--) {
        mod <<= 1;

        if (mod > m) {
            break;
        }
    }

    printf("%d\n", m % mod);

    return 0;
}