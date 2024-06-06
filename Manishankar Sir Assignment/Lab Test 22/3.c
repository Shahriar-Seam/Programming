#include <stdio.h>
#include <string.h>
#include <ctype.h>

void trim_string(char *str)
{
    int i, len = strlen(str), index = 0;

    for (i = 0; i < len; i++) {
        if (str[i] != ' ') {
            index = i;
            break;
        }
    }

    for (i = 0; str[i] != '\0'; i++) {
        str[i] = str[index + i];
    }

    len = strlen(str);

    for (i = len - 1; i >= 0; i--) {
        if (str[i] != ' ') {
            str[i + 1] = '\0';
            break;
        }
    }
}

int main()
{
    char str[100];

    gets(str);

    trim_string(str);

    puts(str);

    return 0;
}