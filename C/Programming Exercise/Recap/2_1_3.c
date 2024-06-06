#include <stdio.h>

int main()
{
    int i, taka = 0, t;

    for (i = 0; i < 3; i++) {
        scanf("%d", &t);
        taka += t;
    }

    printf("Biryani: %d", taka >= 375);

    return 0;
}