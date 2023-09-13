#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);

    if (n % 100 == 0) {
        if (n % 400 == 0) {
            printf("Leap Year.\n");
        }
        else {
            printf("Not leap year.\n");
        }
    }
    else if (n % 4 == 0) {
        printf("Leap year.\n");
    }
    else {
        printf("Not leap year.\n");
    }

    return 0;
}