#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100], str[200];
    int i, j, len1, len2, len;

    gets(str1);
    gets(str2);

    len1 = strlen(str1);
    len2 = strlen(str2);
    len = len1 + len2;

    for (i = 0; i < len1; i++) {
        str[i] = str1[i];
    }

    for (i, j = 0; i < len; i++, j++) {
        str[i] = str2[j];
    }

    printf("%s\n", str);

    return 0;
}