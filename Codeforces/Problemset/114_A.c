#include <stdio.h>

int log_k(int k, int n)
{
    long long l, p = k;

    for (l = 0; p < n; l++, p *= k);

    return p == n ? l : -1;
}

int main()
{
    int k, l;

    scanf("%d %d", &k, &l);

    l = log_k(k, l);

    if (l == -1) {
        puts("NO");
    }
    else {
        printf("YES\n%d\n", l);
    }

    return 0;
}