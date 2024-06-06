#include <stdio.h>
#include <string.h>

int main()
{
    int t, x = 0;
    char str[4];

    scanf("%d", &t);
    getchar();

    while (t--) {
        gets(str);

        if ((strcmp(str, "X++") == 0) || (strcmp(str, "++X") == 0)) {
            x++;
        }
        else if ((strcmp(str, "--X") == 0) || (strcmp(str, "X--") == 0)) {
            --x;
        }
    }

    printf("%d", x);

    return 0;
}