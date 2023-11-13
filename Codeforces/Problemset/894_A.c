#include <stdio.h>
#include <string.h>

int main()
{
    char str[102];
    int len, i, j, k, count = 0;

    gets(str);

    len = strlen(str);

    for (i = 0; i < len - 2; i++) {
        if (str[i] == 'Q') {
            for (j = i + 1; j < len - 1; j++) {
                if (str[j] == 'A') {
                    for (k = j + 1; k < len; k++) {
                        if (str[k] == 'Q') {
                            count++;
                        }
                    }
                }
            }
        }
    }

    printf("%d", count);

    return 0;
}