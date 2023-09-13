#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, A, B;
    double pi = acos(-1);

    printf("Enter a, b: ");
    scanf("%lf %lf", &a, &b);

    b *= 2.54;

    A = pi * pow(a, 2);
    B = pi * pow(b, 2);

    if (A > B) {
        printf("A is bigger Than B.\n");
    }
    else if (B > A) {
        printf("B is bigger than A.\n");
    }
    else {
        printf("Both are equal.\n");
    }

    return 0;
}