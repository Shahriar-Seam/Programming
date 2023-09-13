#include <stdio.h>

int main()
{
    float a;

    scanf("%f", &a);
    printf("Volume = %.2f cubic unit\nSurface area = %.2f sq. unit\n", a * a * a, 6 * a * a);

    return 0;
}