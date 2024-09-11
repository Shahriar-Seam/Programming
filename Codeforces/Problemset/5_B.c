#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    char all[1000][1001];
    char s[1009];
    int i = 0, j = 0, max_len = 0, n = 0;
    int len[1000] = {}, counter = 0;

    while (gets(all[i]) != NULL) {
        len[i] = strlen(all[i]);

        max_len = max(max_len, len[i]);

        i++;
    }

    n = i;

    for (i = 0; i < max_len + 2; i++) {
        s[i] = '*';
    }

    puts(s);

    for (i = 0; i < n; i++) {
        printf("*");

        if ((len[i] % 2) == (max_len % 2)) {
            for (j = 0; j < (max_len - len[i]) / 2; j++) {
                s[j] = ' ';
            }

            s[j] = '\0';

            printf("%s%s%s", s, all[i], s);
        }
        else {
            for (j = 0; j < (max_len - len[i]) / 2; j++) {
                s[j] = ' ';
            }

            s[j] = '\0';

            if (counter % 2 == 0) {
                printf("%s%s%s ", s, all[i], s);
            }
            else {
                printf(" %s%s%s", s, all[i], s);
            }

            counter++;
        }
        
        printf("*\n");
    }

    for (i = 0; i < max_len + 2; i++) {
        s[i] = '*';
    }

    puts(s);

    return 0;
}