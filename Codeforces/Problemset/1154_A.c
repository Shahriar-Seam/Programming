#include <stdio.h>

int main()
{
    int ab, ac, bc, abc, a, b, c, t;

    scanf("%d %d %d %d", &ab, &ac, &bc, &abc);

    if (ab > ac) {
        t = ab;
        ab = ac;
        ac = t;
    }
    if (ac > bc) {
        t = ac;
        ac = bc;
        bc = t;
    }
    if (bc > abc) {
        t = bc;
        bc = abc;
        abc = t;
    }

    c = abc - ab;
    b = bc - c;
    a = ac - c;

    printf("%d %d %d", a, b, c);

    return 0;
}