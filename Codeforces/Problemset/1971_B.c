#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *all_chars_same(char *s, int *f)
{
    int i;
    
    for (i = 1; s[i] != '\0'; i++) {
        if (s[i] != s[i - 1]) {
            *f = 1;

            return "YES";
        }
    }

    return "NO";
}

void swap(char *a, char *b)
{
    *a ^= *b ^= *a ^= *b;
}

void solve()
{
    int i, f = 0;
    char s[11];

    scanf(" %s", s);

    puts(all_chars_same(s, &f));

    for (i = 1; s[i] != '\0'; i++) {
        if (s[i] != s[0]) {
            swap(s + i, s + 0);

            break;
        }
    }

    if (f == 1) {
        puts(s);
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