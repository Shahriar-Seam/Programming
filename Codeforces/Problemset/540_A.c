#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b)
{
    if (a < b) {
        return a;
    }
    else {
        return b;
    }
}

int main()
{
    int n, i, r1, r2, sum = 0;
    char *str1, *str2;

    scanf("%d", &n);
    getchar();

    str1 = (char *) malloc(sizeof(char) * (n + 1));
    str2 = (char *) malloc(sizeof(char) * (n + 1));

    gets(str1);
    gets(str2);

    for (i = 0; i < n; i++) {
        r1 = str1[i] - '0';
        r2 = str2[i] - '0';

        sum += min(abs(r1 - r2), abs(10 - abs(r1 - r2)));
    }

    printf("%d", sum);

    return 0;
}