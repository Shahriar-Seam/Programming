#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100], str[201];
    int len1, len2, len, i;

    gets(str1);
    gets(str2);

    len1 = strlen(str1);
    len2 = strlen(str2);
    len = len1 + len2;

    for (i = 0; i < len1; i++) {
        str[i] = str1[i];
    }

    for (i; i < len; i++) {
        str[i] = str2[i - len1];
    }

    str[i] = '\0';

    puts(str);

    return 0;
}