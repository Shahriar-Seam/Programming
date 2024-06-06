#include <stdio.h>
#include <string.h>

int _count(char str[])
{
    int i, len = strlen(str), count = 0;

    for (i = 0; i < len - 1; i++) {
        if (str[i] == 'A' && str[i + 1] == 'B') {
            count++;
            str[i] = 'B';
            str[i + 1] = 'C';
        }
        if (str[i] == 'B' && str[i + 1] == 'A') {
            count++;
            str[i] = 'C';
            str[i + 1] = 'B';
        }
    }

    return count;
}

int main()
{
    int t;
    char str[200002];

    scanf("%d", &t);

    while (t--) {
        scanf(" %s", str);

        int c = 1, count = 0;

        while (c) {
            c = _count(str);
            count += c;
        }

        printf("%d\n", count);
    }

    return 0;
}