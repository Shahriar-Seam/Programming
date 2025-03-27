#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <stdarg.h>
#include <limits.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int _max(int count, ...)
{
    int i, max_value = INT_MIN;
    va_list ptr;

    va_start(ptr, count);

    for (i = 0; i < count; i++) {
        max_value = max(max_value, va_arg(ptr, int));
    }

    va_end(ptr);

    return max_value;
}

int count(char *s, int n, char c)
{
    int i, cnt = 0;

    for (i = 0; i < n; i++) {
        cnt += (s[i] == c);
    }

    return cnt;
}

void solve()
{
    char s[200005];
    int i, j, l = -1, r = -1, n;

    scanf(" %s", s);

    n = strlen(s);

    if ((strstr(s, "BB") != NULL) || (s[0] == 'B') || (s[n - 1] == 'B')) {
        printf("%d\n", count(s, n, 'A'));

        return;
    }

    if (count(s, n, 'B') == 1) {
        for (i = 0; i < n; i++) {
            if (s[i] == 'B') {
                l = i;
                break;
            }
        }
        
        printf("%d\n", max(count(s, l + 1, 'A'), count(s + l, n - l, 'A')));

        return;
    }

    if (count(s, n, 'B') == 0 || count(s, n, 'A') == 0) {
        printf("0\n");

        return;
    }

    for (i = 0; i < n; i++) {
        if (l == -1 && s[i] == 'B') {
            l = i;
            j = i;

            continue;
        }

        if (r == -1 && s[i] == 'B') {
            r = i;
            j = i;

            continue;
        }

        if (s[i] == 'B') {
            if (i - j < r - l) {
                r = i;
                l = j;
            }

            j = i;
        }
    }

    printf("%d\n", _max(3, count(s, l + 1, 'A') + count(s + r, n - r, 'A'), count(s + l, n - l, 'A'), count(s, r, 'A')));
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