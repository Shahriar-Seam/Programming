#include <stdio.h>

int main()
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if (a && b && c) {
        printf("Pizza.\n");
    }
    else if ((a && b) || (b && c) || (c && a)) {
        printf("Chinese.\n");
    }
    else if (a || b || c) {
        printf("Ice Cream.\n");
    }
    else if (!a && !b && !c) {
        printf("Chocolate.\n");
    }

    return 0;
}