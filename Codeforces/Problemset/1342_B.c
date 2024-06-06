#include <stdio.h>
#include <string.h>

int main()
{
    int t, n, i;
    char s[102];

    scanf("%d", &t);

    while (t--) {
        scanf(" %s", s);

        n = strlen(s);

        if (strstr(s, "0") == 0 || strstr(s, "1") == 0) {
            puts(s);

            continue;
        }

        for (i = 0; i < 2 * n; i++) {
            putchar('0' + i % 2);
        }

        puts("");
    }

    return 0;
}