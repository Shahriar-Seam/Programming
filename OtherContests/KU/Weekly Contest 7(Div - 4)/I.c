#include <stdio.h>
#include <stdint.h>

int32_t main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        int a, b, n, count = 0, temp;

        scanf("%d %d %d", &a, &b, &n);

        if (a > b) {
            temp = a;
            a = b;
            b = temp;
        }

        while (b <= n) {
            if (a < b) {
                temp = a;
                a = b;
                b = temp;
            }

            b += a;

            count++;
        }

        printf("%d\n", count);
    }

    return 0;
}