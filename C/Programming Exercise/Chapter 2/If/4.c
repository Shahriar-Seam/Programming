#include <stdio.h>

int main()
{
    int n1, n2, n3, n4, n5, n6, m = 0;

    scanf("%d %d %d %d %d %d", &n1, &n2, &n3, &n4, &n5, &n6);

    if (n1 >= 1000000) {
        m += 1;
    }
    if (n2 >= 1000000) {
        m += 1;
    }
    if (n3 >= 1000000) {
        m += 1;
    }
    if (n4 >= 1000000) {
        m += 1;
    }
    if (n5 >= 1000000) {
        m += 1;
    }
    if (n6 >= 1000000) {
        m += 1;
    }

    printf("Number of millionaires: %d\n", m);

    return 0;
}