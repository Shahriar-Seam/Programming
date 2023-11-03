#include <stdio.h>
#include <math.h>

int main()
{
    int n, k, i, j;
    char str[60], str2[12];

    scanf("%d", &k);
    getchar();

    gets(str);

    n = (-1 + sqrt(1 + 8 * k)) / 2;

    for (i = 0, j = 0; i <= n; i++) {
        str2[j++] = str[i * (i + 1) / 2];
    }

    str2[j] = '\0';

    puts(str2);

    return 0;
}