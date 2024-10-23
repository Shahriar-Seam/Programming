#include <stdio.h>

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        int n, m, i, sum = 0;

        scanf("%d %d", &n, &m);

        char sa[n + 1], sb[m + 1];
        int counter[26] = {};

        scanf(" %s %s", sa, sb);

        for (i = 0; i < n; i++) {
            counter[sa[i] - 'a']++;
        }

        for (i = 0; i < m; i++) {
            counter[sb[i] - 'a']++;
        }

        for (i = 0; i < 26; i++) {
            sum += (counter[i] > 0);
        }

        if (sum < 26) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}