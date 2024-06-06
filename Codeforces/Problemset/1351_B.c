#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int t, a, b, c, d, area;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d %d", &a, &b, &c, &d);

        if (a > b) {
            swap(&a, &b);
        }
        if (c > d) {
            swap(&c, &d);
        }

        if (b == d && a + c == b) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}