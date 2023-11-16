#include <stdio.h>

int main()
{
    int num, n, temp, i, count = 1, max = 1;

    scanf("%d %d", &num, &temp);

    for (i = 1; i < num; i++) {
        scanf ("%d", &n);

        if (temp < n) {
            count++;
        }
        else {
            count = 1;
        }

        if (max < count) {
            max = count;
        }

        temp = n;
    }

    printf("%d\n", max);

    return 0;
}