#include <stdio.h>

void solve()
{
    int i, j;
    char s1[1000005], s2[1000005];

    scanf(" %s %s", s1, s2);

    for (i = 0, j = 0; s2[j] != '\0'; j++) {
        if (s1[i] == s2[j]) {
            i++;
        }
        else if (j == 0 || s2[j] != s2[j - 1]) {
            break;
        }
    }

    puts((s2[j] != '\0' || s1[i] != '\0') ? "NO" : "YES");
}

int main()
{
    int t, i, j;
    
    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}