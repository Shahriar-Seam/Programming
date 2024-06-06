#include <stdio.h>

void decToBin(int dec)
{
    int d, q, i = 6, bin[50];

    while(1) {
        d = dec / 2;
        q = dec % 2;
        bin[i] = q;
        dec = d;
        i--;

        if (dec == 0) {
            break;
        }
    }

    for (int i = 0; i < 7; i++) {
        printf("%d", bin[i]);
    }
}

int main()
{
    int decimal = 95;
    decToBin(decimal);
    return 0;
}