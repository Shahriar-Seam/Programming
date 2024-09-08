#include <stdio.h>

int main()
{
    int i, j, f = 1;
    char s[3][4];

    scanf("%s %s %s", s[0], s[1], s[2]);

    if (s[0][0] != s[2][2] || s[0][2] != s[2][0]) {
        f = 0;
    }
    if (s[0][1] != s[2][1] || s[1][0] != s[1][2]) {
        f = 0;
    }

    puts(f == 1 ? "YES" : "NO");

    return 0;
}