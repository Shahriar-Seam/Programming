#include <stdio.h>

int main()
{
    double t;

    scanf("%lf", &t);

    if (t >= 12.5) {
        printf("Shajahan sir.\n");
    }
    else if (t >= 11.5) {
        printf("Jahangir sir.\n");
    }
    else if (t >= 11) {
        printf("Tiffin break.\n");
    }
    else if (t >= 10) {
        printf("Akbor sir.\n");
    }
    else if (t >= 9) {
        printf("Humayun sir.\n");
    }
    else if (t >= 8) {
        printf("Babor sir.\n");
    }

    return 0;
}