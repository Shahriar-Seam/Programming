#include <stdio.h>

void solve()
{
    int i;
    long long int count = 0, cost = 0;
    char s[200005];

    scanf(" %s", s);

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '0') {
            cost += (count == 0 ? count : count + 1);
        }
        else {
            count++;
        }
    }

    printf("%lld\n", cost);
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