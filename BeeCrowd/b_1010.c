#include <stdio.h>

int main()
{
    int code1, code2;
    double a, A, b, B;

    scanf("%d %lf %lf", &code1, &a, &A);
    scanf("%d %lf %lf", &code2, &b, &B);

    printf("VALOR A PAGAR: R$ %0.2lf\n", (a * A) +(b * B));

    return 0;
}