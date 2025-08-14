#include <stdio.h>
#include <stdint.h>

int32_t main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        int a, b;

        scanf("%d %d", &a, &b);

        printf("%d\n", (b - (a % b)) % b);
    }

    return 0;
}