#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    if (n ^ m) {
        puts("Numbers are not equal");
    }
    else {
        puts("Numbers are equal");
    }

    return 0;
}