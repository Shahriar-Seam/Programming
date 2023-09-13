#include <stdio.h>

int check_sum(char *str)
{
    int i, sum1 = 0, sum2 = 0;

    for (i = 0; i < 3; i++) {
        sum1 += str[i] - '0';
    }
    for (i; i < 6; i++) {
        sum2 += str[i] - '0';
    }

    if (sum1 == sum2) {
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{
    int t;
    char str[7];

    scanf("%d", &t);

    while (t--) {
        scanf(" %s", str);

        if (check_sum(str) == 1) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}