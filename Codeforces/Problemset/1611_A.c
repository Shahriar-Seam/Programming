#include <stdio.h>

int intlen(int n)
{
    int len = 0;

    while (n != 0) {
        len++;
        n /= 10;
    }

    return len;
}

int check_even_digit(int n, int len)
{
    int i, f, r;

    for (i = 0; i < len; i++) {
        r = n % 10;

        if (r % 2 == 0) {
            return 1;
        }

        n /= 10;
    }

    return 0;
}

int rev_int(int n, int len)
{
    int rev = 0, i;

    for (i = 0; i < len; i++) {
        rev *= 10;
        rev += n % 10;
        n /= 10;
    }

    return rev;
}

int main()
{
    int t;
    int n, i, len;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        len = intlen(n);

        if (n % 2 == 0) {
            printf("0\n");
        }
        else if (rev_int(n, len) % 2 == 0) {
            printf("1\n");
        }
        else if (check_even_digit(n, len)) {
            printf("2\n");
        }
        else {
            printf("-1\n");
        }
    }

    return 0;
}