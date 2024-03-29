#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return * (int *) a - * (int *) b;
}

int bin_decs[50] = {};
int size = 0;

int is_binary_decimal(int n)
{
    while (n > 0) {
        if (n % 10 > 1) {
            return 0;
        }

        n /= 10;
    }

    return 1;
}

void binary_decimals()
{
    int i;

    for (i = 1; i <= 100000; i++) {
        if (is_binary_decimal(i) == 1) {
            bin_decs[size++] = i;
        }
    }

    bin_decs[size++] = 11 * 11;
    bin_decs[size++] = 11 * 111;
    bin_decs[size++] = 11 * 1111;
    bin_decs[size++] = 11 * 1011;
    bin_decs[size++] = 11 * 1101;
    bin_decs[size++] = 11 * 1001;
    bin_decs[size++] = 111 * 111;
    bin_decs[size++] = 111 * 101;
    bin_decs[size++] = 101 * 101;
    bin_decs[size++] = 121 * 11;
    bin_decs[size++] = 121 * 111;
    bin_decs[size++] = 121 * 121;
}


bool binary_search(int n)
{
    int l = 0, r = size - 1, m;

    while (l <= r) {
        m = (l + r) / 2;

        if (n == bin_decs[m]) {
            return true;
        }

        if (n < bin_decs[m]) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    return false;
}

void solve()
{
    int n, i = 0, f = 1;

    scanf("%d", &n);

    while (n % 10 == 0) {
        n /= 10;
    }

    puts(binary_search(n) == true ? "YES" : "NO");
}

int main()
{
    binary_decimals();

    qsort(bin_decs, size, sizeof(int), compare);

    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}