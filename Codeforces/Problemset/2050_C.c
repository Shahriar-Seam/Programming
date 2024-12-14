#include <stdio.h>
#include <string.h>

#define yes printf("YES\n")
#define no printf("NO\n")

void solve()
{
    int n, i, j, sum = 0, two = 0, three = 0;
    int remaining;
    char s[100005];

    scanf(" %s", s);

    n = strlen(s);

    for (i = 0; i < n; i++) {
        sum += s[i] - '0';

        two += (s[i] == '2');
        three += (s[i] == '3');
    }

    remaining = 9 - (sum % 9);

    if (remaining == 9) {
        yes;

        return;
    }

    for (i = 0; i <= two; i++) {
        for (j = 0; j <= three; j++) {
            if (((i * 2 + j * 6) % 9) == remaining) {
                yes;

                return;
            }

            if (i * 2 + j * 6 > 100) {
                break;
            }
        }
    }

    no;
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