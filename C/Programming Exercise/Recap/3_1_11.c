#include <stdio.h>
#include <math.h>

int binary(int n)
{
    int i, len, bin = 0, r, j = 1;

    len = (int) log2(n);

    for (i = 0; i <= len; i++) {
        r = n % 2;
        bin += r * j;
        j *= 10;
        n /= 2;
    }

    return bin;
}

int main()
{
    int n, bin;

    scanf("%d", &n);

    bin = binary(n);

    printf("%d\n", bin);

    return 0;
}