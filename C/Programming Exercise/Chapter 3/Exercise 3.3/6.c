#include <stdio.h>

void reversed_multiplication_table(int n)
{
    int i;

    for (i = 10; i > 0; i--) {
        printf("%2d x %2d = %3d\n", n, i, i * n);
    }

    return;
}

int main()
{
    int n, i;

    for (i = 0; i < 10; i++) {
        scanf("%d", &n);

        reversed_multiplication_table(n);

        printf("---------------------------------\n");
    }

    return 0;
}