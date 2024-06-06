#include <stdio.h>
#include <string.h>

int main()
{
    char str1[101], str2[101], str[201];
    int i, len;

    printf("Enter 2 strings of same length:\n");
    gets(str1);
    gets(str2);
    len = strlen(str1);

    for (i = 0; i < len; i++) {
        str[2 * i] = str1[i];
        str[2 * i + 1] = str2[i];
    }
    str[2 * i] = '\0';

    printf("New string: %s", str);

    return 0;
}