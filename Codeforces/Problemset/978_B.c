#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int len, x = 0, count = 0, i;
    char *str;

    scanf("%d", &len);
    getchar();

    str = (char *) malloc(sizeof(char) * len);

    gets(str);

    for (i = 0; i < len; i++) {
        if (str[i] == 'x' && str[i + 1] == 'x') {
            x++;
        }
        else {
            x = 0;
        }

        if (x >= 2) {
            count++;
        }
    }

    printf("%d", count);

    free(str);

    return 0;
}