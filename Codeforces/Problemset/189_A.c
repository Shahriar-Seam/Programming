#include <stdio.h>

int main() {
    int x, y, a, b, c, n, z, ans = 0, r;

    scanf("%d %d %d %d", &n, &a, &b, &c);

    for (x = 0; x * a <= n; x++) {
        for (y = 0; x * a + y * b <= n; y++) {
            r = n - x * a - y * b;

            if (r % c == 0) {
                z = r / c;
                ans = (ans > (x + y + z)) ? ans : (x + y + z);
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
