#include <stdio.h>

int main()
{
    int m;

    scanf("%d", &m);

    if (m >= 80) {
        printf("A+");
    }
    else if (m >= 70) {
        printf("A");
    }
    else if (m >= 60) {
        printf("A-");
    }
    else if (m >= 50) {
        printf("B");
    }
    else if (m >= 40) {
        printf("C");
    }
    else if (m >= 33) {
        printf("D");
    }
    else if (m >= 0) {
        printf("F");
    }

    return 0;
}