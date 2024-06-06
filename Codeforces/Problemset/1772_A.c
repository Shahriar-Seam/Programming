#include <stdio.h>

int main()
{
    int a, b;
    char ch;
    int t;

    scanf("%d", &t);

    while (t--) {
        scanf("%d%c%d", &a, &ch, &b);

        printf("%d\n", a + b);
    }

    return 0;
}