#include <stdio.h>
#include <string.h>

int even(char *str, int len, int *f1)
{
    int i, j, c1 = 1000;

    for (i = len - 1; i >= 0; i--) {
        if (str[i] == '0') {
            c1 = len - i - 1;

            for (j = i - 1; j >= 0; j--) {
                if (str[j] == '0' || str[j] == '5') {
                    c1 += i - j - 1;
                    *f1 = 1;
                    break;
                }
            }

            break;
        }
    }

    return c1;
}

int odd(char *str, int len, int *f2)
{
    int i, j, c2 = 1000;

    for (i = len - 1; i >= 0; i--) {
        if (str[i] == '5') {
            c2 = len - i - 1;

            for (j = i - 1; j >= 0; j--) {
                if (str[j] == '2' || str[j] == '7') {
                    c2 += i - j - 1;
                    *f2 = 1;
                    break;
                }
            }

            break;
        }
    }

    return c2;
}

int main()
{
    int t, i, j, k, len, c1, c2, f1, f2;
    char str[20];

    scanf("%d", &t);
    getchar();

    while (t--) {
        gets(str);

        len = strlen(str);
        c1 = c2 = 1000;
        f1 = f2 = 0;

        c1 = even(str, len, &f1);
        c2 = odd(str, len, &f2);

        if (!f1) {
            printf("%d\n", c2);
            continue;
        }
        else if (!f2) {
            printf("%d\n", c1);
            continue;
        }
        

        (c1 < c2) ? printf("%d\n", c1) : printf("%d\n", c2);
    }

    return 0;
}