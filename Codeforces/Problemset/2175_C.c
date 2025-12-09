#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

static const int sz = 1e5 + 5;

void solve()
{
    char s[sz], t[sz], v[sz], final[sz];
    int n, m, i, j, k;
    int cnt_s[26] = {}, cnt_t[26] = {};

    scanf("%[^\n] ", s);
    scanf("%[^\n] ", t);

    n = strlen(s);
    m = strlen(t);

    for (i = 0; i < n; i++) {
        cnt_s[s[i] - 'a']++;
    }

    for (i = 0; i < m; i++) {
        cnt_t[t[i] - 'a']++;
    }

    for (i = 25, k = 0; i >= 0; i--) {
        if (cnt_s[i] > cnt_t[i]) {
            puts("Impossible");

            return;
        }
        else {
            for (j = 0; j < cnt_t[i] - cnt_s[i]; j++, k++) {
                v[k] = 'a' + i;
            }
        }
    }

    for (i = 0, j = k - 1, k = 0; k < m; k++) {
        final[k] = (i < n && j >= 0) ? (s[i] <= v[j] ? s[i++] : v[j--]) : (i < n ? s[i++] : v[j--]);
    }

    final[k] = 0;

    puts(final);
}

int32_t main()
{
    int32_t t;

    scanf("%d ", &t);

    while (t--) {
        solve();
    }

    return 0;
}