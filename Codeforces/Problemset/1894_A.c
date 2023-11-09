#include <stdio.h>
#include <string.h>

int main()
{
    int t, n;
    char str[25];

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        getchar();

        gets(str);

        printf("%c\n", str[n - 1]);
    }

    return 0;
}