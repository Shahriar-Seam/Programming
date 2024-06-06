#include <stdio.h>
#include <string.h>

int main()
{
    char T[4];
    char str_a[102];
    char str_b[102];
    int len, i, j, t;

    gets(T);

    t = atoi(T);

    while (t--) {
        gets(str_a);

        len = strlen(str_a);

        for (i = 0, j = 0; i < len; i += 2, j++) {
            str_b[j] = str_a[i];
        }

        str_b[j++] = str_a[len - 1];
        str_b[j] = '\0';

        puts(str_b);
    }

    return 0;
}