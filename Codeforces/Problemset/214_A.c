#include <stdio.h>

#define nn (a * a + b == n)
#define mm (a + b * b == m)

int main()
{
    int n, m, a, b, count = 0, s;

    scanf("%d %d", &n, &m);

    s = (n < m) ? n : m;

    for (a = 0; a <= s; a++) {
        for (b = 0; b <= s; b++) {
            if (nn && mm) {
                count++;
            }
        }
    }

    printf("%d", count);

    return 0;
}