#include <stdio.h>
#include <string.h>

int main()
{
    int t, len, i, same;

    char str[52];

    scanf("%d", &t);
    getchar();

    while (t--) {
        gets(str);

        len = strlen(str);
        same = 1;

        for (i = 1; i < len; i++) {
            if (str[i] != str[i - 1]) {
                same = 0;
                break;
            }
        }

        if (same) {
            printf("-1\n");
        }
        else {
            printf("%d\n", len - 1);
        }
    }

    return 0;
}