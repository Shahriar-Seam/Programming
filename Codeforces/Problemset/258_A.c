#include <stdio.h>
#include <string.h>

int main()
{
    char s[100005];
    int i, len, index, f = 0;

    scanf("%s", s);

    len = strlen(s);
    index = len - 1;

    for (i = len - 1; i >= 0; i--) {
        if (f == 0 && s[i] == '1') {
            f = 1;
        }
        if (f == 1 && s[i] == '0') {
            index = i;
        }
    }

    for (i = 0; i < len; i++) {
        if (i != index) {
            putchar(s[i]);
        }
    }

    return 0;
}