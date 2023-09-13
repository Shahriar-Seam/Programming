#include <stdio.h>

int main()
{
    int school, shift;

    printf("Choose your school:\n0. Polashdanga School.\n1. Noren Ganguly School\n");
    scanf("%d", &school);
    printf("Choose your shift:\n0. Morning\n1. Day\n");
    scanf("%d", &shift);

    if (school == 0 && shift == 0) {
        printf("The badge color is: Yellow");
    }
    else if (school == 0 && shift == 1) {
        printf("The badge color is: Green");
    }
    else if (school == 1 && shift == 0) {
        printf("The badge color is: Blue");
    }
    else if (school == 1 && shift == 1) {
        printf("The badge color is: Red");
    }

    return 0;
}