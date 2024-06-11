#include <stdio.h>

void solve()
{
    char s1[4], s2[4];

    scanf(" %s %s", s1, s2);

    char temp = s1[0];
    s1[0] = s2[0];
    s2[0] = temp;

    printf("%s %s\n", s1, s2);
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