#include <stdio.h>

int main()
{
    int n, i;

    scanf("%d", &n);

    char s[n + 1];

    for (i = 0; i < n; i += 4) {
        s[i] = 'a';
        s[i + 1] = 'a';
    }

    for (i = 2; i < n; i += 4) {
        s[i] = 'b';
        s[i + 1] = 'b';
    }

    s[n] = '\0';

    puts(s);

    return 0;
}