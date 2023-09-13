#include <stdio.h>

int main()
{
    int rain, france_goal, spain_goal;

    scanf("%d %d %d", &rain, &france_goal, &spain_goal);
    printf("France proceed to next round -> %d", (france_goal > spain_goal) && !rain);

    return 0;
}