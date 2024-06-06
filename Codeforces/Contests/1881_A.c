#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int t, len1, len2, i, f;
    char *str1, *str2, temp[4000];

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &len1, &len2);
        getchar();

        str1 = (char *) malloc(sizeof(char) * (len1 * 128 + 1));
        str2 = (char *) malloc(sizeof(char) * (len2 + 1));

        f = 0;

        gets(str1);
        gets(str2);

        for (i = 0; i < 7; i++) {
            if (strstr(str1, str2) != NULL) {
                f = 1;
                break;
            }
            else {
                strcpy(temp, str1);
                strcat(str1, temp);
            }
        }

        if (f == 1) {
            printf("%d\n", i);
        }
        else {
            printf("-1\n");
        }

        free(str2);
    }

    return 0;
}