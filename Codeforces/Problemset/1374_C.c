#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve()
{
    int n, count = 0, left = 0, i;
    char *s;

    scanf("%d", &n);
    getchar();

    s = malloc(sizeof(char) * (n + 1));

    gets(s);

    for (i = 0; i < n; i++) {
        if (s[i] == '(') {
            left++;
        }
        else {
            left--;
        }

        if (left < 0) {
            count++;

            left = 0;
        }
    }

    printf("%d\n", count);
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