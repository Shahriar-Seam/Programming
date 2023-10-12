#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void _count(char *str, int *o, int *z)
{
    int i, len = strlen(str);

    for (i = 0; i < len; i++) {
        if (str[i] == '0') {
            (*z)++;
        }
        else {
            (*o)++;
        }
    }
}

int main()
{
    int o = 0, z = 0, n, r;
    char str[200005];

    scanf("%d", &n);
    getchar();

    gets(str);

    _count(str, &o, &z);

    r = abs(o - z);

    printf("%d", r);

    return 0;
}