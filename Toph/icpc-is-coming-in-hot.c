#include <stdio.h>

int _max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int i, max = 0;
    int count[10] = {};
    char str[10005];

    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++) {
        count[str[i] - '0']++;
    }

    for (i = 0; i < 10; i++) {
        max = _max(max, count[i]);
    }

    for (i = 0; i < 10; i++) {
        if (count[i] == max) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}