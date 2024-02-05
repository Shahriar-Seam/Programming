#include <stdio.h>

int _max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n, i, total = 0, max = 0, temp;
    int count[1001] = {};

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &temp);

        count[temp]++;

        if (count[temp] == 1) {
            total++;
        }

        max = _max(max, count[temp]);
    }

    printf("%d %d\n", max, total);

    return 0;
}