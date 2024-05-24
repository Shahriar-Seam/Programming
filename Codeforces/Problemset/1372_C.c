/**
 *    author:  Anonymous_HF
 *    created: 24/05/2024 10:43:27
**/

#include <stdio.h>

void solve()
{
    int n, i, count = 0, temp, f = 0, f1 = 0, f2 = 0;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &temp);

        if (temp == i) {
            if (f1 == 1) {
                f = 1;
            }

            count++;
        }
        else if (f1 == 0) {
            f1 = 1;
        }
        else if (f1 == 1 && f == 1) {
            f2 = 1;
        }
    }

    if (count == n) {
        printf("0\n");
    }
    else if ((count == 0) || (f1 == 0 || f2 == 0)) {
        printf("1\n");
    }
    else {
        printf("2\n");
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