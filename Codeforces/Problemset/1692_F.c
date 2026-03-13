#include <stdio.h>
#include <stdint.h>

int comb[22][3] = {
        {0, 0, 3}, 
        {0, 1, 2}, 
        {0, 4, 9}, 
        {0, 5, 8}, 
        {0, 6, 7}, 
        {1, 1, 1}, 
        {1, 3, 9}, 
        {1, 4, 8}, 
        {1, 5, 7}, 
        {1, 6, 6}, 
        {2, 2, 9}, 
        {2, 3, 8}, 
        {2, 4, 7}, 
        {2, 5, 6}, 
        {3, 3, 7}, 
        {3, 4, 6}, 
        {3, 5, 5}, 
        {4, 4, 5}, 
        {5, 9, 9}, 
        {6, 8, 9}, 
        {7, 7, 9}, 
        {7, 8, 8}
    };

void solve()
{
    int n, i, j, a, f;
    int counter[10] = {};

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &a);

        counter[a % 10]++;
    }

    for (i = 0; i < 22; i++) {
        f = 1;

        for (j = 0; j < 3; j++) {
            counter[comb[i][j]]--;

            if (counter[comb[i][j]] < 0) {
                f = 0;
            }
        }

        for (j = 0; j < 3; j++) {
            counter[comb[i][j]]++;
        }

        if (f) {
            printf("YES\n");

            return;
        }
    }

    printf("NO\n");
}

int32_t main()
{
    int32_t t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}