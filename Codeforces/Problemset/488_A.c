#include <stdio.h>

int is_lucky(int a)
{
    if (a < 0) {
        a *= -1;
    }

    while (a > 0) {
        if (a % 10 == 8) {
            return 1;
        }

        a /= 10;
    }

    return 0;
}

int main()
{
    int a, count = 1;

    scanf("%d", &a);

    a++;

    while (!is_lucky(a)) {
        count++;
        a++;
    }

    printf("%d\n", count);

    return 0;
}