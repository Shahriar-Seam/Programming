#include <stdio.h>

int main()
{
    int t, n, count;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        if (n % 3 == 0) {
            printf("Second\n");
        }
        else {
            printf("First\n");
        }
    }

    return 0;
}