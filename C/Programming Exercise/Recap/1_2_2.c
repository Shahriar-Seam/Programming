#include <stdio.h>
#include <math.h>

int main(){
    double x, a, b, c, d, e;
    double E = 2.718281828;
    double pi = acos(-1);

    printf("Enter value of x: ");
    scanf("%lf", &x);

    a = pow(x, 2) - 5 * x + 12;

    b = pow(E, 5 * x - 1);

    c = sin(x * pi / 360);

    d = pow(cos(2 * x - 1), 2);

    e = log2(pow(x, 3)) + 3 * x - 1;

    printf("a = %.2lf\nb = %.2lf\nc = %.2lf\nd = %.2lf\ne = %.2lf\n", a, b, c, d, e);

    return 0;
}