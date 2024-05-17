/**
 *    author:  Anonymous_HF
 *    created: 17/05/2024 11:09:28
**/

#include <stdio.h>

void solve()
{
    int n, i, cnt = 0, k = 0;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);

        cnt += (arr[i] == 2);
    }

    if (cnt % 2 == 1) {
        printf("-1\n");
    }
    else {
        cnt /= 2;

        for (i = 0; i < n; i++) {
            cnt -= (arr[i] == 2);

            if (cnt == 0) {
                k = i + 1;

                break;
            }
        }

        printf("%d\n", k);
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