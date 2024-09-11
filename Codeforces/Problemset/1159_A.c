#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n, i, count = 0;

    scanf("%d", &n);

    char s[n + 1];

    scanf(" %s", s);

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '-') {
            count = max(0, count - 1);
        }
        else {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}