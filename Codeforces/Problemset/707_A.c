#include <stdio.h>

int main()
{
    int a, b;
    int i, j, color = 0;
    char ch;

    scanf("%d %d", &a, &b);

    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            scanf(" %c", &ch);

            if ((ch == 'C') || (ch == 'M') || (ch == 'Y')) {
                color = 1;
            }
        }
    }

    (color == 1) ? printf("#Color") : printf("#Black&White");

    return 0;
}