#include <stdio.h>

int main()
{
    double a, b, c;
    double tri, cir, tra, squ, rec;
    double pi = 3.14159;

    scanf("%lf %lf %lf", &a, &b, &c);

    tri = a * c / 2.0;
    cir = pi * c * c;
    tra = (a + b) * c / 2.0;
    squ = b * b;
    rec = a * b;

    printf("TRIANGULO: %0.3lf\n", tri);
    printf("CIRCULO: %0.3lf\n", cir);
    printf("TRAPEZIO: %0.3lf\n", tra);
    printf("QUADRADO: %0.3lf\n", squ);
    printf("RETANGULO: %0.3lf\n", rec);

    return 0;
}