#include <stdio.h>

void solve()
{
    int n, i, j;
    long long points = 0;

    scanf("%d", &n);

    long long arr[n];
    long long prefix[n + 1];
    char s[n + 1];

    for (i = 0; i < n; i++) {
        scanf("%lld", arr + i);
    }

    scanf(" %s", s);
    
    prefix[0] = 0;

    for (i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + arr[i];
    }

    for (i = 0, j = n; i < j; i++) {
        if (s[i] == 'L') {
            while (j > i && s[j] != 'R') {
                j--;
            }

            if (j > i) {
                points += prefix[j + 1] - prefix[i];

                j--;
            }
        }
    }

    printf("%lld\n", points);
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