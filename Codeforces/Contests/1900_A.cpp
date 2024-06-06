#include <stdio.h>

int main()
{
    int t, n, i, count, sum, started;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        char str[n + 1];
        sum = started = count = 0;

        scanf("%s", str);

        for (i = 0; i < n; i++) {
            if ((str[i] == '.' && str[i + 1] == '#') || (str[i] == '#' && str[i + 1] == '.')) {
                count++;
                i++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}