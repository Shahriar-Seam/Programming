// Try to understand it after learning pointer (After finishing cpbook2)

#include <stdio.h>
#include <stdlib.h>

void solve();

int main()
{
    int t;

    scanf("%d", &t);
    getchar();

    while (t--) {
        solve();
    }
}

void solve()
{
    char line[1002];
    char *p, *e;
    long input;
    int count = 0;
    p = line;

    gets(line);

    for (p = line; ; p = e) {
        input = strtol(p, &e, 10);
        if (p == e) {
            break;
        }
        count++;
    }

    printf("%d\n", count);
}