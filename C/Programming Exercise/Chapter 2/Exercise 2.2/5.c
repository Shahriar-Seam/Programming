#include <stdio.h>

int main()
{
    int seat, passengers;

    scanf("%d %d", &seat, &passengers);

    if (seat - passengers >= 5) {
        printf("Yes\n");
    }
    if (seat - passengers < 5) {
        printf("No\n");
    }

    return 0;
}