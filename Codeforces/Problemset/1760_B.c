#include <stdio.h>
#include <string.h>

int main()
{
    int t, n, max, i, temp;
    char str[102];

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        getchar();

        gets(str);

        max = 0;

        for (i = 0; i < n; i++) {
            temp = toascii(str[i]);

            max = (temp > max) ? temp : max;
        }

        printf("%d\n", max - 'a' + 1);
    }

    return 0;
}