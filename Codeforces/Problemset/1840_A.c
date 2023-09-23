#include <stdio.h>
#include <string.h>

int main()
{
    int t, n;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        getchar();

        char str[n];
        char str2[n];
        int j = 0, i;

        gets(str);

        str2[0] = str[0];

        for (i = 1; i < n; i++) {
            if (str[i] == str2[j]) {
                str2[++j] = str[++i];
            }
        }

        str2[j] = '\0';

        puts(str2);
    }

    return 0;
}