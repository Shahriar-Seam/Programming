#include <stdio.h>
#include <string.h>

#define yes printf("YES\n")
#define no printf("NO\n")

int main()
{
    int r, c, i, j, f = 1;
    char str[100][101];

    scanf("%d %d", &r, &c);
    getchar();

    for (i = 0; i < r; i++) {
        gets(str[i]);
    }

    for (i = 0; i < r; i++) {
        for (j = 1; j < c; j++) {
            if (str[i][0] != str[i][j]) {
                f = 0;
                break;
            }
        }

        if (f == 0) {
            break;
        }
    }

    if (f) {
        for (i = 1; i < r; i++) {
            if (strcmp(str[i], str[i - 1]) == 0) {
                f = 0;
                break;
            }
        }
    }

    f ? yes: no;

    return 0;
}