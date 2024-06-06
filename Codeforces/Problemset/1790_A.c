#include <stdio.h>
#include <string.h>

char pi[] = "314159265358979323846264338327";

int _count(char *str)
{
    int i, len = strlen(str), count = 0;

    for (i = 0; i < len; i++) {
        if (str[i] == pi[i]) {
            count++;
        }
        else {
            break;
        }
    }

    return count;
}

int main()
{
    int t;
    char str[32];

    scanf("%d", &t);

    while (t--) {
        scanf(" %s", str);

        printf("%d\n", _count(str));
    }

    return 0;
}