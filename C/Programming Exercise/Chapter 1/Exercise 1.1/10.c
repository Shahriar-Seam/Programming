#include <stdio.h>

int main()
{
    int n, f;

    printf("Enter number of friends and number of boroi: ");
    scanf("%d %d", &f, &n);
    printf("Extra boroi = %d", n % f);

    return 0;
}