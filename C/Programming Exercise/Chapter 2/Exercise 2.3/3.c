#include <stdio.h>

int main()
{
    double a, b;

    scanf("%lf %lf", &a, &b);
    
    b = b * 2.54;

    if (a > b) {
        printf("A is bigger than B\n");
    }
    else {
        printf("B is bigger than A\n");
    }

    return 0;
}