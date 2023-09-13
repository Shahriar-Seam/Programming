#include <stdio.h>

int main()
{
    int a, b, rem;

    scanf("%d %d", &a, &b);

    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    while (b != 0) {
        rem = a % b;
        a = b;
        b = rem;
    }
    
    printf("%d\n", a);

    return 0;
}

// Study more about the Euclidean algorithm.