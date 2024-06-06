#include <stdio.h>

void solve()
{
    int n;

    scanf("%d", &n);

    if (n > 52) {
        printf("%czz\n", (char) 'a' - 1 + n - 52);
    }
    else if (n > 27) {
        printf("a%cz\n", (char) 'a' - 1 + n - 27);
    }
    else {
        printf("aa%c\n", (char) 'a' - 1 + n - 2);
    }
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