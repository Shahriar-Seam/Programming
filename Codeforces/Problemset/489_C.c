#include <stdio.h>
#include <stdlib.h>

char *max(int m, int s)
{
    char *str = (char *) malloc(sizeof(char) * (m + 1));
    int i = 0;

    for (i = 0; i < m; i++) {
        str[i] = '0';
    }

    i = 0;

    while (s >= 10) {
        str[i++] = '9';

        s -= 9;
    }

    str[i++] = s + '0';
    str[m] = '\0';

    return str;
}

char *min(int m, int s)
{
    char *str = (char *) malloc(sizeof(char) * (m + 1));
    int i = 0;

    str[i] = '1';

    for (i = 1; i < m; i++) {
        str[i] = '0';
    }

    for (i = m - 1; s >= 10; i--, s -= 9) {
        str[i] = '9';
    }

    if (i != 0) {
        s--;
    }

    str[i] = s + '0';
    str[m] = '\0';

    return str;
}

int main()
{
    int m, s;

    scanf("%d %d", &m, &s);

    if ((s == 0 && m > 1) || s > 9 * m) {
        printf("-1 -1\n");
    }
    else {
        printf("%s %s\n", min(m, s), max(m, s));
    }

    return 0;
}