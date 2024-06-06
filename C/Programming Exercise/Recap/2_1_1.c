#include <stdio.h>

int main()
{
    int a, b, c, d, e, f, g;
    int A, B, C, D;

    printf("Enter value of A, B, C, D (0 or 1):\n");
    scanf("%d %d %d %d", &A, &B, &C, &D);

    a = A || B;
    b = A && B;
    c = A || !B;
    d = !A && !B;
    e = A || B || C;
    f = (A || B) && (C || D);
    g = A || (B && (!C || D));

    printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n", a, b, c, d, e, f, g);

    return 0;
}