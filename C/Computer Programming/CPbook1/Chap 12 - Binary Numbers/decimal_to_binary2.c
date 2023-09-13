#include <stdio.h>

int main()
{
    int dec = 95, bin[7], d, q, i = 6;

    while (1) {
        d = dec / 2;
        q = dec % 2;
        bin[i] = q;
        dec = d;
        i--;

        if (dec == 0) {
            break;
        }
    }

    for (i = 0; i < 7; i++) {
        printf("%d", bin[i]);
    }

    return 0;
}