#include <stdio.h>

int main()
{
    int rain, france_goal, spain_goal, france_wont_go;

    printf("Did it rain?\n");
    scanf("%d", &rain);
    printf("Enter goal number (Firstly France then Spain):\n");
    scanf("%d %d", &france_goal, &spain_goal);

    france_wont_go = rain || (france_goal <= spain_goal);

    printf("France go: %d", !france_wont_go);
}