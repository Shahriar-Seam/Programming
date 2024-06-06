#include <stdio.h>

int main()
{
    int n, total = 0;

    for (int i = 1; i <= 10; i++) {
        scanf("%d", &n);
        if (n >= 60) {
            total += 1;
        }
    }

    printf("Total people of age 60 or above is %d", total);

    return 0;
}