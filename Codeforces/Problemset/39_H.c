#include <stdio.h>
#include <stdlib.h>

int to_int(char *s, int len)
{
    int num = 0, i;

    for (i = len - 1; i >= 0; i--) {
        num *= 10;

        num += s[i] - '0';
    }
    
    return num;
}

int convert(int n, int radix)
{
    char *s = (char *) malloc(sizeof(char) * 10);
    int i = 0;

    while (n > 0) {
        s[i++] = n % radix + '0';

        n /= radix;
    }

    s[i] = '\0';

    return to_int(s, i);
}

int main()
{
    int n, i, j;

    scanf("%d", &n);

    int mat[10][10];

    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            mat[i][j] = convert(i * j, n);
        }
    }

    for (i = 1; i < n; i++) {
        for (j = 1; j < n; j++) {
            printf("%2d ", mat[i][j]);
        }

        printf("\n");
    }

    return 0;
}