#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_vowel(char c)
{
    c = tolower(c);

    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
    char s[105];
    int i, f;

    gets(s);

    for (i = strlen(s) - 1; i >= 0; i--) {
        if (isalpha(s[i])) {
            if (is_vowel(s[i])) {
                f = 1;
            }
            else {
                f = 0;
            }

            break;
        }
    }

    puts(f == 1 ? "YES" : "NO");

    return 0;
}