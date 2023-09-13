#include <stdio.h>

int main()
{
    int n, num;

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &num);

        if (num % 2 == 0) {
            printf("%d\n", num / 2);
        }
        else {
            printf("%d\n", num * 3 + 1);
        }
    }

    return 0;
}