#include <stdio.h>
#include <string.h>

int main()
{
    char str[1000];
    int len, i, j;

    while (1 == scanf("%s", str)) {
        if ((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= '0' && str[0] <= '9')) {
            if (str[0] >= 'a' && str[0] <= 'z') {
                str[0] = str[0] - 'a' + 'A';
            }

            len = strlen(str);

            for (i = 0; i < len;) {
                if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))) {
                    len--;

                    for (j = i; j < len; j++) {
                        str[j] = str[j + 1];
                    }
                }
                else {
                    i++;
                }
            }

            str[len] = '\0';

            puts(str);
        }
    }

    return 0;
}