#include <stdio.h>

int main()
{
    int temp;

    scanf("%d", &temp);

    if (temp < 0 && temp > -273) {
        printf("Ice\n");
    }
    if (0 < temp && temp < 100) {
        printf("Water\n");
    }
    if (temp > 100) {
        printf("Vapour\n");
    }
    if (temp == 0 || temp == 100) {
        printf("Transitional Stage\n");
    }
    if (temp <= -273) {
        printf("Temperature can't fall below -273%cC.\n", 248);
    }

    return 0;
}