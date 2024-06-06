#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int t, a, b, n, count;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d", &a, &b, &n);

        count = 0;

        while (b <= n) {
            if (a < b) {
                swap(&a, &b);
            }

            b += a;

            count++;
        }

        printf("%d\n", count);
    }

    return 0;
}