#include <stdio.h>

int main()
{
    int n, q;

    scanf("%d", &n);

    if (n & 1) {
        printf("%d is odd\n", n);
    }
    else {
        printf("%d is even\n", n);
    }

    return 0;
}