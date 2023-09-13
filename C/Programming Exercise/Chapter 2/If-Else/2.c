#include <stdio.h>

int main()
{
    double a, b;

    scanf("%lf %lf", &a, &b);

    if (a > b) {
        printf("%g", a);
    }
    else {
        printf("%g", b);
    }
    
    return 0;
}