#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, c = 1, l1, l2;
    char s[52], t[52];

    gets(s);
    gets(t);

    l1 = strlen(s);
    l2 = strlen(t);

    for (i = 0, j = 0; i < l2; i++) {
        if (t[i] == s[j]) {
            c++;
            j++;
        }
    }

    printf("%d", c);

    return 0;
}