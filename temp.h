#include <stdio.h>
#include <stdint.h>
#include <string.h>

int32_t main()
{
    char s[101];

    scanf("%s", s);

    char f[256] = {};

    int count = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char d = s[i];

        if (f[d] == 0) {
            f[d] = 1;

            count++;
        }
    }

    printf("%d", count);

    return 0;
}