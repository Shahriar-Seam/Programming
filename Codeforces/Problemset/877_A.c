#include <stdio.h>
#include <string.h>

int count(char *str, char *s)
{
    int i, j, cnt = 0, len = strlen(s);

    for (i = 0, j = 0; str[i] != '\0'; i++) {
        if (j != 0 && str[i] != s[j]) {
            j = 0;
        }
        
        if (str[i] == s[j]) {
            j++;
        }

        if (j == len) {
            cnt++;
            j = 0;
        }
    }

    return cnt;
}

int main()
{
    int i, cnt = 0;
    char str[105];
    char s[5][10] = {
        "Danil",
        "Olya",
        "Slava",
        "Ann",
        "Nikita"
    };

    gets(str);

    for (i = 0; i < 5; i++) {
        cnt += count(str, s[i]);
    }

    puts(cnt == 1 ? "YES" : "NO");

    return 0;
}