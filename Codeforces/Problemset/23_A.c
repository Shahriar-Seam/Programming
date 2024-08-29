#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    char s[105], sub[105];
    int i, j, len, max_len = 0;

    gets(s);

    len = strlen(s);

    for (i = 0; i < len - 1; i++) {
        for (j = 1; j < len - i + 1; j++) {
            strcpy(sub, "");

            strncpy(sub, s + i, j);

            sub[j] = '\0';

            if (strstr(s + i + 1, sub)) {
                max_len = max(max_len, j);
            }
        }
    }

    printf("%d\n", max_len);

    return 0;
}