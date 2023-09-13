#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);

    // The condition can be written as (n && !(n & (n - 1)))
    if (n > 0 && (n & (n - 1)) == 0) {
        printf("%d is a power of 2\n", n);
    }
    else {
        printf("%d is not a power of 2\n", n);
    }

    return 0;
}