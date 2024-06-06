#include <stdio.h>

int main()
{
    int n;
    int rm_second_place, rm_first_place;

    scanf("%d", &n);

    if (n < 0) {
        rm_first_place = n / 10;
        rm_second_place = (n / 100) * 10 + (n % 10);

        if (rm_first_place > rm_second_place) {
            printf("%d", rm_first_place);
        }
        else {
            printf("%d", rm_second_place);
        }
    }

    else {
        printf("%d", n);
    }

    return 0;
}