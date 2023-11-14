#include <stdio.h>
#include <math.h>

int main()
{
    int n2, n;

    scanf("%d", &n2);

    n = round(sqrt((double) n2));

    printf("%d\n", n);

    return 0;
}