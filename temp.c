#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);
    int x = 9;
    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= i; j--) {
            printf("  ");
        }

        for (int k = i; k <= x; k++) {
            printf("%d ", k);
        }

        for (int m = x - 1; m >= i; m--) {
            printf("%d ", m);
        }

        printf("\n");

        x -= 2;
    }

    return 0;
}