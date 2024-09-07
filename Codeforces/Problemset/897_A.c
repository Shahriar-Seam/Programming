#include <stdio.h>

int main()
{
    int n, m, l, r, i;
    char c1, c2, s[105];

    scanf("%d %d", &n, &m);
    scanf(" %s", s);

    while (m--) {
        scanf("%d %d %c %c", &l, &r, &c1, &c2);

        l--;

        for (i = l; i < r; i++) {
            if (s[i] == c1) {
                s[i] = c2;
            }
        }
    }

    puts(s);

    return 0;
}