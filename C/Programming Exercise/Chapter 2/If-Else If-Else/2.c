#include <stdio.h>

int main()
{
    int bus, trawler, auto_rickshaw, money;

    scanf("%d %d %d %d", &bus, &trawler, &auto_rickshaw, &money);

    if (money >= auto_rickshaw) {
        printf("Auto rickshaw.\n");
    }
    else if (money >= trawler) {
        printf("Trawler.\n");
    }
    else if (money >= bus) {
        printf("Bus.\n");
    }
    else {
        printf("Walk");
    }

    return 0;
}