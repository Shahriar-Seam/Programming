#include <stdio.h>
#include <string.h>

int main()
{
    int m, l, r, i;
    char s[100005];
    int prefix[100005] = {};

    gets(s);

    scanf("%d", &m);

    for (i = 1; s[i] != '\0'; i++) {
        if (s[i] == s[i - 1]) {
            prefix[i] = prefix[i - 1] + 1;
        }
        else {
            prefix[i] = prefix[i - 1];
        }
    }

    while (m--) {
        scanf("%d %d", &l, &r);

        printf("%d\n", prefix[r - 1] - prefix[l - 1]);
    }

    return 0;
}