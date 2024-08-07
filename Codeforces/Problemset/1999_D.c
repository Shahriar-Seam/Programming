#include <stdio.h>
#include <string.h>

#define size 200005

void solve()
{
    char s[size], t[size];
    int ls, lt, i, j;

    scanf(" %s %s", s, t);

    ls = strlen(s);
    lt = strlen(t);

    for (i = 0; i < ls; i++) {
        if (s[i] == t[0] || s[i] == '?') {
            j = 0;

            while (i < ls && j < lt) {
                if (s[i] == t[j] || s[i] == '?') {
                    s[i] = t[j++];
                }
                i++;
            }

            break;
        }
    }

    for (i = 0; i < ls; i++) {
        if (s[i] == '?') {
            s[i] = 's';
        }
    }

    if (j == lt) {
        puts("YES");
        puts(s);
    }
    else {
        puts("NO");
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