#include <stdio.h>

int main()
{
    long int t, n, s1, e1, s, e, f;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        scanf("%d %d", &s1, &e1);

        f = 1;

        while (--n) {
            scanf("%d %d", &s, &e);

            if (s >= s1 && e >= e1) {
                f = 0;
            }
        }

        f ? printf("%d\n", s1) : printf("-1\n");
    }

    return 0;
}