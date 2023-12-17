#include <stdio.h>

int len(int n)
{
    int i = 0;

    while (n > 0) {
        n /= 10;
        i++;
    }

    return i;
}

int make_10(int i)
{
    int j, temp = 1;

    for (j = 0; j < i; j++) {
        temp *= 10;
    }

    return temp;
}

int main()
{
    int n, i, k, temp, j, m;

    scanf("%d", &n);

    i = m = len(n);

    while (n > 10) {
        temp = make_10(i);

        n = n % temp;

        i--;

        temp = n;

        k = i;

        for (j = 2; j < 2 * (m - i); j++) {
            printf(" ");
        }

        for (j = 0; j < len(n); j++) {
            printf("%d ", (temp / make_10(k--)) % 10);
        }

        printf("\n");
    }

    return 0;
}