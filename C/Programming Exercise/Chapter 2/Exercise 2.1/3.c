#include <stdio.h>

int main()
{
    int taka1, taka2, taka3, taka0, can_eat;

    scanf("%d %d %d", &taka1, &taka2, &taka3);

    taka0 = taka1 + taka2 + taka3;

    can_eat = taka0 >= 375;

    printf("Can they eat? -> %d", can_eat);

    return 0;
}