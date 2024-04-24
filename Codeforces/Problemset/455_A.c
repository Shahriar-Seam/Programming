#include <stdio.h>

long long int max(long long int a, long long int b)
{
    return a > b ? a : b;
}

int main()
{
    int n, i, temp;
    int cnt[100005] = {};
    long long int heh[100005] = {};

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &temp);

        cnt[temp]++;
    }

    heh[0] = 0;

    for (i = 1; i < 100005; i++) {
        heh[i] = 1LL * i * cnt[i];
        
        if (i >= 2) {
            heh[i] += heh[i - 2];
        }

        heh[i] = max(heh[i], heh[i - 1]);
    }

    printf("%lld\n", heh[100004]);

    return 0;
}