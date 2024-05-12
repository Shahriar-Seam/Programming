#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    char str[1000005];
    int i, count = 0, cnt = 1;

    scanf("%s", str);

    for (i = 0; str[i + 1] != '\0'; i++) {
        if (str[i] == str[i + 1]) {
            cnt++;
        }
        else {
            count = max(count, cnt);

            cnt = 1;
        }
    }

    count = max(count, cnt);

    printf("%d\n", count);

    return 0;
}