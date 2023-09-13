#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);

    if (3 <= n && n <= 5) {
        printf("Primary.\n");
    }
    else if (6 <= n && n <= 8) {
        printf("Junior.\n");
    }
    else if (9 <= n && n <= 10) {
        printf("Secondary.\n");
    }
    else if (11 <= n && n <= 12) {
        printf("Higher Secondary.\n");
    }
    else {
        printf("Not eligible.\n");
    }

    return 0;
}