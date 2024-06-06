#include <stdio.h>
#include <string.h>

int main()
{
    int n, q, a, b, count, i;

    scanf("%d %d", &n, &q);
    getchar();

    char str[n + 1];

    gets(str);

    while (q--) {
        scanf("%d %d", &a, &b);

        count = 0;

        for (i = a - 1; i < b - 1; i++) {
            if (str[i] == str[i + 1]) {
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}