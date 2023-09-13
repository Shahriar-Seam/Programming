#include <stdio.h>

int main()
{
    float n, w;

    scanf("%f %f", &n, &w);
    printf("%.2f kg", n * w / 1000);

    return 0;
}