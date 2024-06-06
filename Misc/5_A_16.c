#include <stdio.h>

int _count(int n)
{
    int i, cnt = 0;

    for (i = 2; i <= n / 2; i++) {
        if (n % i == 0) {
            cnt++;
        }
    }

    return (cnt >= 3) ? 1 : 0;
}

int main()
{
    int s, f, i;

    scanf("%d %d", &s, &f);

    if (s > f) {
        int temp = s;
        s = f;
        f = temp;
    }

    for (i = s; i <= f; i++) {
        if (_count(i) == 1) {
            printf("%d\n", i);
        }
    }

    return 0;
}