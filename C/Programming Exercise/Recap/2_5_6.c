#include <stdio.h>

int main()
{
    int school, shift;

    printf("Select school:\n0. Polashdanga School\n1. Noren Ganguly School\n");
    scanf("%d", &school);

    printf("Select shift:\n0. Morning\n1. Day\n");
    scanf("%d", &shift);

    if (!school) {
        if (!shift) {
            printf("Badge: Yellow.\n");
        }
        else {
            printf("Badge: Green.\n");
        }
    }

    else {
        if (!shift) {
            printf("Badge: Blue.\n");
        }
        else {
            printf("Badge: Red.\n");
        }
    }

    return 0;
}