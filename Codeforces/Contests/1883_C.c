#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, n, k, num, r, m, f, e;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &k);

        m = f = e = 0;

        if (k == 4) {
            m = 2;

            while (n--) {
                scanf("%d", &num);

                if (num % 2 == 0) {
                    e++;
                }

                if (num % 4 == 0) {
                    f = 1;
                }

                if (num % 4 == 3) {
                    m = 1;
                }
            }

            if (f) {
                printf("0\n");
            }
            else if (e >= 2) {
                printf("0\n");
            }
            else if (e == 1) {
                printf("1\n");
            }
            else if (m == 1) {
                printf("1\n");
            }
            else {
                printf("2\n");
            }

            continue;
        }

        while (n--) {
            scanf("%d", &num);

            r = num % k;

            if (r == 0) {
                f = 1;
            }

            else if (r > m) {
                m = r;
            }
        }

        f ? printf("0\n") : printf("%d\n", k - m);
    }

    return 0;
}