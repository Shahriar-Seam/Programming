#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int _count(int n)
{
    int count = 1;

    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;

            count++;
        }
        else {
            n = 3 * n + 1;

            count++;
        }
    }

    return count;
}

int main()
{
    int i, j, k, count, max;

    while (scanf("%d %d", &i, &j) == 2) {
        max = 0;

        printf("%d %d ", i, j);

        if (i > j) {
            swap(&i, &j);
        }

        for (k = i; k <= j; k++) {
            count = _count(k);

            if (count >= max) {
                max = count;
            }
        }

        printf("%d\n", max);
    }

    return 0;
}