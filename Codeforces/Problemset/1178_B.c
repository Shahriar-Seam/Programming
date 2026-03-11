#include <stdio.h>
#include <stdint.h>
#include <string.h>

int32_t main()
{
    char s[1000005], t[1000005];
    int n, i, j;
    long long count = 0, w = 0, o = 0;

    gets(s);

    n = strlen(s);

    for (i = 1, j = 0; i < n; i++) {
        if (s[i] == 'o') {
            t[j++] = 'o';
        }
        else if (s[i] == 'v' && s[i - 1] == 'v') {
            t[j++] = 'w';
        }
    }

    t[j] = 0;

    for (i = 0; i < j; i++) {
        if (t[i] == 'w') {
            count += o;
            w++;
        }
        else {
            o += w;
        }
    }

    printf("%lld\n", count);

    return 0;
}