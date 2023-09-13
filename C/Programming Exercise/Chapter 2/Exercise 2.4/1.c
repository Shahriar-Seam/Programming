#include <stdio.h>

int main()
{
    int temp;

    scanf("%d", &temp);

    if (temp < 0) {
        printf("Solid.\n");
    }
    else if (0 <= temp && temp <= 100) {
        printf("Liquid.\n");
    }
    else if (temp > 100) {
        printf("Gaseous.\n");
    }

    return 0;
}