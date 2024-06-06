#include <stdio.h>

int main()
{
    int n, t, i;
    char num[102];

    scanf("%d %d", &n, &t);

    if (t == 10) {
        if (n == 1) {
            printf("-1");
        }
        else {
            for (i = 0; i < n - 1; i++) {
                num[i] = t - 1 + '0';
            }

            num[i++] = '0';
            num[i] = '\0';

            puts(num);
        }
    }
    else {
        for (i = 0; i < n; i++) {
            num[i] = t + '0';
        }

        num[i] = '\0';

        puts(num);
    }

    return 0;
}