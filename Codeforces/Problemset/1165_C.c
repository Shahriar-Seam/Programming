#include <stdio.h>

int main()
{
    int n, i, j;

    scanf("%d", &n);

    char s[n + 1];
    char good[n + 1];

    scanf(" %s", s);

    for (i = 0, j = 0; i < n; i++) {
        if (j % 2 == 0 || good[j - 1] != s[i]) {
            good[j++] = s[i];
        }
    }

    if (j % 2 == 1) {
        good[j - 1] = '\0';

        j = j - 1;
    }
    else {
        good[j] = '\0';
    }

    printf("%d\n%s\n", n - j, good);

    return 0;
}