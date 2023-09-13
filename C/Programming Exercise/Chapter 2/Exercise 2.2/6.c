#include <stdio.h>
#include <math.h>

int main()
{
    int n;

    scanf("%d", &n);

    if (pow(floor(sqrt((double) n)), 2) == n) {
        printf("%d is a perfect square number.\n");
    }
    if (pow(floor(sqrt((double) n)), 2) != n) {
        printf("%d is not a perfect square number.\n");
    }

    return 0;
}