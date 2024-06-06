#include <stdio.h>

int main()
{
    int A, B, C, D;

    scanf("%d %d %d %d", &A, &B, &C, &D);

    printf("A OR B = %d\n", A || B);
    printf("A AND B = %d\n", A && B);
    printf("A OR NOT B = %d\n", A || !B);
    printf("NOT A AND NOT B = %d\n", !A && !B);
    printf("A OR B OR C = %d\n", A || B || C);
    printf("(A OR B) AND (C OR D) = %d\n", (A || B) && (C || D));
    printf("A OR (B AND (NOT C OR D)) = %d\n", A || (B && (!C || D)));

    return 0;
}