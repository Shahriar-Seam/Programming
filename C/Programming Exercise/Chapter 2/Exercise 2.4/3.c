#include <stdio.h>

int main()
{
    int juta, porbot, pahar, tila;

    scanf("%d %d %d %d", &juta, &porbot, &pahar, &tila);

    if (juta == porbot) {
        printf("Porbot.\n");
    }
    else if (juta == pahar) {
        printf("Pahar.\n");
    }
    else if (juta == tila) {
        printf("Tila.\n");
    }
    else {
        printf("Online e beche dibo.\n");
    }

    return 0;
}