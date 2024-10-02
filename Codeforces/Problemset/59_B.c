#include <stdio.h>

int main()
{
    int n, temp, sum = 0, odd = 1000;

    scanf("%d", &n);

    while (n--) {
        scanf("%d", &temp);

        if ((temp % 2 == 1) && temp < odd) {
            odd = temp;
        }

        sum += temp;
    }

    printf("%d\n", sum % 2 == 1 ? sum : odd == 1000 ? 0 : sum - odd);

    return 0;
}