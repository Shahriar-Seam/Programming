#include <stdio.h>
#include <string.h>

int main()
{
    int n, x, y, i, count = 0;

    scanf("%d %d %d", &n, &x, &y);

    char s[n + 1];

    scanf(" %s", s);

    for (i = n - x; i < n; i++) {
        if ((i != n - y - 1) && s[i] == '1') {
            count++;
        }
    }

    if (s[n - y - 1] == '0') {
        count++;
    }

    printf("%d\n", count);

    return 0;
}