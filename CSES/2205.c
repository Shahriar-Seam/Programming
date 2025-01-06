#include <stdio.h>
#include <string.h>

#define sz (1 << 16)

char t1[sz][17], t2[sz][17];

void generate(char s[][17], int index)
{
    int i, j, n = (1 << (index - 1));

    for (i = 0; i < n; i++) {
        for (j = 0; j < index - 1; j++) {
            t1[i][j + 1] = t2[i][j + 1] = s[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        t1[i][0] = '0';
        t2[i][0] = '1';
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < index; j++) {
            s[i][j] = t1[i][j];
            s[i + n][j] = t2[n - i - 1][j];
        }
    }
}

void grey_code(char s[][17], int n, int index)
{
    if (index <= n) {
        generate(s, index);

        grey_code(s, n, index + 1);
    }
}

int main()
{
    int n;
    char grey[sz][17] = {};

    grey[0][0] = '0';
    grey[1][0] = '1';

    scanf("%d", &n);

    grey_code(grey, n, 2);

    for (i = 0; i < (1 << n); i++) {
        printf("%s\n", grey[i]);
    }

    return 0;
}