#include <stdio.h>

int akaimma[] = {1, 2, 3, 5, 7, 11};

int is_present(int n)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (akaimma[i] == n) {
            return 1;
        }
    }

    return 0;
}

void solve()
{
    int n, k = -1;

    scanf("%d", &n);

    k = n / 4;

    for (k; k > 0; k--) {
        if (is_present(n - 4 * k) == 0) {
            break;
        }
    }

    if (n - 4 * k == 0) {
        // bleh
    }
    else if ((n - 4 * k) % 15 == 0) {
        k += 2;
    }
    else if (((n - 4 * k) % 6 == 0) || ((n - 4 * k) % 9 == 0)) {
        k++;
    }

    if (k == 0) {
        k = -1;
    }

    printf("%d\n", k);
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}