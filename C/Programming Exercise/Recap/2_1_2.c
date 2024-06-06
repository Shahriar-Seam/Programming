#include <stdio.h>

int main()
{
    int school_open, competition_on;

    printf("Is school open?\n");
    scanf("%d", &school_open);

    printf("Is there an art competition?\n");
    scanf("%d", &competition_on);

    printf("Early rising: %d", school_open || competition_on);

    return 0;
}