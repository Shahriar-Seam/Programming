#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

void add(int *h, int *m, int x)
{
    int min = *h * 60 + *m + x;

    *h = (min / 60) % 24;
    *m = min % 60;
}

char *to_str(int n)
{
    char *s = (char *) malloc(2 * sizeof(char));

    s[0] = '0' + n / 10;
    s[1] = '0' + n % 10;

    return s;
}

int is_palindrome(int h, int m)
{
    char *H = to_str(h);
    char *M = to_str(m);

    return H[0] == M[1] && H[1] == M[0];
}

void solve()
{
    int h, m, x, t = 1e5, count = 0;
    int counter[24][60] = {};

    scanf("%d:%d %d", &h, &m, &x);

    while (t--) {
        if (is_palindrome(h, m)) {
            counter[h][m] = 1;
        }

        add(&h, &m, x);
    }

    for (h = 0; h < 24; h++) {
        for (m = 0; m < 60; m++) {
            count += counter[h][m];
        }
    }

    printf("%d\n", count);
}

int32_t main()
{
    int32_t t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}