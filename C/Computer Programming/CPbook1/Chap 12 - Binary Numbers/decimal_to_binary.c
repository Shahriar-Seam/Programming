#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char binary[7];
    int decimal, i, j, sum;

    decimal = 95;

    for (i = 0; i < 7; i++) {
        binary[i] = '1';
    }

    for (i = 6; i >= 0; i--) {
        sum = 0;
        for (j = 6; j >= 0; j--) {
            sum += (binary[j] - '0') * pow(2, j);
        }
        if (sum >= 95) {
            binary[j] = '0';
        }

        printf("%d\n", sum);
    }

    return 0;
}

// Don't know how to solve this... :(