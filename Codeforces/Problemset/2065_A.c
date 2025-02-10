#include <stdio.h>
#include <string.h>

void solve()
{
    char s[15];
    int i;

    scanf(" %s", s);

    for (i = 0; i < strlen(s) - 2; i++) {
        printf("%c", s[i]);
    }

    puts("i");
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