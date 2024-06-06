#include <stdio.h>

int main()
{
    int school_open, art;

    scanf("%d %d", &school_open, &art);

    printf("Early rising = %d", school_open || art);

    return 0;
}