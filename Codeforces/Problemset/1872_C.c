#include <stdio.h>

void solve()
{
    int l, r, i;

    scanf("%d %d", &l, &r);

    if (l < 4) {
        if (r < 4) {
            printf("-1\n");
        }
        else {
            printf("2 2\n");
        }
    }
    else if (l == r) {
        for (i = 2; i * i <= l; i++) {
            if (l % i == 0) {
                printf("%d %d\n", i, l - i);

                return;
            }
        }

        printf("-1\n");
    }
    else if (l % 2 == 0) {
        printf("%d %d\n", l / 2, l / 2);
    }
    else {
        l++;
        printf("%d %d\n", l / 2, l / 2);
    }
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}