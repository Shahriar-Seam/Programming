#include <stdio.h>
#include <string.h>

void solve()
{
    char s[15];
    int i, len, index;

    scanf(" %s", s);

    len = strlen(s);
    index = len;

    for (i = 1; s[i] != '\0'; i++) {
        if (s[i - 1] == s[i]) {
            index = i;

            break;
        }
    }

    for (i = len; i > index; i--) {
        s[i] = s[i - 1];
    }

    if (index > 0) {
        s[index] = 'a' + (s[index - 1] - 'a' + 1) % 26;
    }
    else {
        s[index] = 'a' + (s[index + 1] - 'a' + 1) % 26;
    }

    s[len + 1] = '\0';

    puts(s);
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