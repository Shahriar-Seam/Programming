#include <stdio.h>

int main()
{
    char c;
    int n, i;

    c = getchar();
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("%c\n", c);
    }

    return 0;
}