#include <stdio.h>

int main()
{
    int a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (a + b + c == d) {
        printf("%d + %d + %d = %d\n", a, b, c, d);
    }
    else if (b + c + d == a) {
        printf("%d + %d + %d = %d\n", b, c, d, a);
    }
    else if (c + d + a == b) {
        printf("%d + %d + %d = %d\n", c, d, a, b);
    }
    else if (d + a + b == c) {
        printf("%d + %d + %d = %d\n", d, a, b, c);
    }
    else {
        printf("No such integer.\n");
    }

    return 0;
}