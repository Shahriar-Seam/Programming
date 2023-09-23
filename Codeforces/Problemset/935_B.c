#include <stdio.h>

int main()
{
    int n, i, r = 0, u = 0, count = 0;

    scanf("%d", &n);
    getchar();

    char str[n];

    gets(str);

    for (i = 0; i < n; i++) {
        if (str[i] == 'R') r++;
        else u++;

        if (r == u && str[i] == str[i + 1]) count++;
    }

    printf("%d", count);

    return 0;
}