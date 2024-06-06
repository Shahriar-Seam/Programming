#include <stdio.h>

int main()
{
    int n, m, i = 1, count = 0;

    scanf("%d %d", &n, &m);

    while (1) {
        i = i % n;

        if (i == 0) {
            i = n;
        }

        if (m - i < 0) {
            count = m;
            break;
        }
        else {
            m -= i;
            i++;
        }
    }

    printf("%d\n", count);

    return 0;
}