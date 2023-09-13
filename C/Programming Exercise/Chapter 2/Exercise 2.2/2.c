#include <stdio.h>

int main()
{
    int taka, ticket;

    scanf("%d %d", &ticket, &taka);

    if (taka >= ticket) {
        printf("YES\n");
    }
    if (taka < ticket) {
        printf("NO\n");
    }

    return 0;
}