#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    long long int n, k, i, j;
    long long int num;

    scanf("%d", &t);

    while (t--) {
        scanf("%lld %lld", &n, &k);

        num = k + (k - 1) / (n - 1);

        printf("%lld\n", num);
    }

    return 0;
}