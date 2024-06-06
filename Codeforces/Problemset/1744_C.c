#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _max(int a, int b)
{
  return a > b ? a : b;
}

void solve()
{
    int n, i, time = 0, r = 0;
    char c, *s, *str;

    scanf("%d %c", &n, &c);

    s = (char *) calloc(n + 1, sizeof(char));
    str = (char *) calloc(2 * n + 1, sizeof(char));

    scanf(" %s", s);

    strcat(str, s);
    strcat(str, s);

    for (i = 2 * n - 2; i >= 0; i--) {
        if (str[i] == 'g') {
            r = i;
        }
        if (str[i] == c) {
            time = _max(time, r - i);
        }
    }

    printf("%d\n", time);

    free(str);
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