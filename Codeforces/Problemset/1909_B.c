#include <stdio.h>

int main()
{
    int t, n, i, two, not_two, three, not_three;
    long long int temp;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        two = not_two = three = not_three = 0;

        for (i = 0; i < n; i++) {
            scanf("%lld", &temp);

            if (temp % 2 == 0) {
                two = 1;
            }
            else {
                not_two = 1;
            }

            if (temp % 3 == 0) {
                three = 1;
            }
            else {
                not_three = 1;
            }
        }

        if (two && not_two) {
            printf("2\n");
        }
        else if (not_two) {
            printf("4\n");
        }
        else if (three && not_three) {
            printf("3\n");
        }
        else {
            printf("6\n");
        }
    }

    return 0;
}