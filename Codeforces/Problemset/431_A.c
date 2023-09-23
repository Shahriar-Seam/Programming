#include <stdio.h>
#include <string.h>

int main()
{
    int a, b, c, d, count = 0, i;
    char str[100002];

    scanf("%d %d %d %d", &a, &b, &c, &d);
    getchar();
    scanf("%s", str);

    int len = strlen(str);

    for (i = 0; i < len; i++) {
        switch (str[i] - '0')
        {
        case 1:
            count += a;
            break;
        case 2:
            count += b;
            break;
        case 3:
            count += c;
            break;
        case 4:
            count += d;
            break;
        }
    }

    printf("%d", count);

    return 0;
}