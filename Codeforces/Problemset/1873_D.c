#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int t, n, k, len;
    char *str;
    int i, count;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &k);
        getchar();

        str = (char *) malloc(sizeof(char) * (n + 1));

        gets(str);

        len = strlen(str);
        count = 0;

        for (i = 0; i < len; i++) {
            if (str[i] == 'B') {
                count++;
                i += k - 1;
            }
        }

        printf("%d\n", count);

        free(str);
    }

    return 0;
}