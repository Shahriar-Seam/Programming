#include <stdio.h>
#include <string.h>

int main()
{
    int t, i, j, k;
    char str[8][9];
    char str1[9];

    scanf("%d", &t);
    getchar();

    while (t--) {
        for (i = 0; i < 8; i++) {
            gets(str[i]);
        }

        for (i = 0, k = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (str[i][j] != '.') {
                    str1[k++] = str[i][j];
                }
            }
        }

        str1[k] = '\0';

        puts(str1);
    }

    return 0;
}