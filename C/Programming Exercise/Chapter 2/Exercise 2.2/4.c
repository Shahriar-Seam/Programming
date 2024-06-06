#include <stdio.h>

int main()
{
    int chocolate, animals;

    scanf("%d %d", &animals, &chocolate);

    if (chocolate >= animals) {
        printf("YES\n");
    }
    if (chocolate < animals) {
        printf("NO\n");
    }

    return 0;
}