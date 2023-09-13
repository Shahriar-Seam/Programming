#include <stdio.h>

int main()
{
    int n, f;

    printf("Enter number of friends and number of boroi: ");
    scanf("%d %d", &f, &n);
    printf("Sobai boroi pabe %d ti kore\n", n / f);
    printf("Extra boroi = %d\n", n % f);

    return 0;
}