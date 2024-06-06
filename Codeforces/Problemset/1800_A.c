#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int main()
{
    int t, n, i, j, len;
    char *str, *str2;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        getchar();

        str = (char *) malloc(sizeof(char) * (n + 1));
        str2 = (char *) malloc(sizeof(char) * (n + 1));

        gets(str);

        len = strlen(str);

        for (i = 0; i < len; i++) {
            str[i] |= 32;
        }

        str2[0] = str[0];
        j = 1;

        for (i = 0; i < len - 1; i++) {
            if (str[i] != str[i + 1]) {
                str2[j++] = str[i + 1];
            }
        }

        str2[j] = '\0';

        (strcmp(str2, "meow") == 0) ? yes : no;

        free(str);
        free(str2);
    }

    return 0;
}