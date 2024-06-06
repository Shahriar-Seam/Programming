#include <stdio.h>

int int_len(int n)
{
    int len = 0;

    while (n != 0) {
        len++;
        n /= 10;
    }

    return len;
}

int main()
{
    int t;
    int n, d, len, pressed;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        d = n % 10;
        len = int_len(n);

        pressed = (d - 1) * 10 + len * (len + 1) / 2;

        printf("%d\n", pressed);
    }

    return 0;
}