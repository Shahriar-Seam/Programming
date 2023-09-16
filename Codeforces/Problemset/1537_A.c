#include <stdio.h>

int main()
{
    int t1, t2, n, num, sum;

    scanf("%d", &t1);

    while (t1--) {
        scanf("%d", &t2);

        sum = 0;
        n = t2;

        while (t2--) {
            scanf("%d", &num);

            sum += num;
        }

        if (sum < n) {
            printf("1\n");
        }
        else if (sum == n) {
            printf("0\n");
        }
        else {
            printf("%d\n", sum - n);
        }
    }

    return 0;
}