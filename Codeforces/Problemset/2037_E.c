#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *make_string(int cnt, int len, int n)
{
    char *s = (char *) malloc(sizeof(char) * (n + 1));
    int i = 0;

    for (i = 0; i < len - cnt - 1; i++) {
        s[i] = '1';
    }

    for (i; i < len - 1; i++) {
        s[i] = '0';
    }

    s[i] = '1';
    s[i + 1] = '\0';

    return s;
}

int count(char *s)
{
    int n = strlen(s), i, cnt = 0, zero = 0;

    for (i = 0; i < n; i++) {
        if (s[i] == '0') {
            zero++;
        }
        else {
            cnt += zero;
        }
    }

    return cnt;
}

int _count(char *s, char c)
{
    int i, n = strlen(s), cnt = 0;

    for (i = 0; i < n; i++) {
        if (s[i] == c) {
            cnt++;
        }
    }

    return cnt;
}

void solve()
{
    int n, i, j, cnt, one = 0, f = 0, zero = 0, prev_cnt = 0;

    scanf("%d", &n);

    char *s = (char *) calloc(n + 1, sizeof(char));

    for (i = 2; i <= n; i++) {
        printf("? %d %d\n", 1, i);

        fflush(stdout);

        scanf("%d", &cnt);

        if (cnt > 0 && f == 0) {
            s = make_string(cnt, i, n);

            one = _count(s, '1');
            zero = _count(s, '0');
            prev_cnt = count(s);

            for (j = i; j < n; j++) {
                s[j] = '0';
            }

            f = 1;

            continue;
        }

        if (cnt != 0 && cnt > prev_cnt) {
            s[i - 1] = '1';

            prev_cnt += zero;

            one++;
        }
        else {
            zero++;
        }
    }

    s[n] = '\0';

    if (cnt == 0 || cnt != count(s)) {
        printf("! IMPOSSIBLE\n");
    }
    else {
        printf("! %s\n", s);
    }

    fflush(stdout);
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