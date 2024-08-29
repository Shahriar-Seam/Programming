#include <stdio.h>

int main()
{
    int n, i;

    scanf("%d ", &n);

    char s[n + 1];

    gets(s);

    if (n % 2 == 0) {
        for (i = 0; i < n; i++) {
            putchar(s[i]);

            if (i > 0 && i < n - 1 && (i % 2 == 1)) {
                putchar('-');
            }
        }
    }
    else {
        printf("%c%c%c", s[0], s[1], s[2]);

        if (n > 3) {
            printf("-");
        }

        
        for (i = 3; i < n; i++) {
            putchar(s[i]);

            if (i > 3 && i < n - 1 && (i % 2 == 0)) {
                putchar('-');
            }
        }
    }

    return 0;
}