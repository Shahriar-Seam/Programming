#include <stdio.h>
#include <string.h>

#define abba (ab_a != ba_a && ab_b != ba_b)

int main()
{
    char str[100005];
    int i, f_ab = 0, f_ba = 0;
    int len;

    gets(str);

    len = strlen(str);

    for (i = 0; i < len - 1; i++) {
        if (str[i] == 'A' && str[i + 1] == 'B') {
            f_ab = 1;
            break;
        }
    }

    i += 2;

    for (i; i < len - 1; i++) {
        if (str[i] == 'B' && str[i + 1] == 'A') {
            f_ba = 1;
            break;
        }
    }

    if (f_ab && f_ba) {
        printf("YES\n");
    }

    else {
        f_ab = f_ba = 0;

        for (i = 0; i < len - 1; i++) {
            if (str[i] == 'B' && str[i + 1] == 'A') {
                f_ba = 1;
                break;
            }
        }

        i += 2;

        for (i; i < len - 1; i++) {
            if (str[i] == 'A' && str[i + 1] == 'B') {
                f_ab = 1;
                break;
            }
        }

        if (f_ab && f_ba) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}