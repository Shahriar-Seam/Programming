#include <stdio.h>
#include <string.h>

int main()
{
    int i, len;
    char str[20];

    gets(str);

    len = strlen(str);

    if ((str[0] != '9') && (str[i] > '4')) {
        str[0] = '0' + '9' - str[0];
    }

    for (i = 1; i < len; i++) {
        if (str[i] > '4') {
            str[i] = '0' + '9' - str[i];
        }
    }

    str[len] = '\0';

    puts(str);

    return 0;
}