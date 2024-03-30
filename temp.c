#include <stdio.h>
#include <math.h>

// #define M_PI 3.1415926535897932384626433832795028841971693993751L

int main(void) {

    const long double PI = M_PI;

    printf("Size of double: %d\n", (int)sizeof(double));
    printf("Size of long double: %d\n", (int)sizeof(long double));

    printf("PI == %.6Lg\n", PI);

    return 0;

}