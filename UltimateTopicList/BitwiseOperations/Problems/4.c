#include <stdio.h>

int main()
{
    int N, i;

    scanf("%d %d", &N, &i);

    puts((N & (1 << i)) == 0 ? "false" : "true");

    return 0;
}