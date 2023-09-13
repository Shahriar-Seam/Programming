#include <stdio.h>

int main()
{
    int x, y, z, m;

    printf("Enter prices of books and his money: ");
    scanf("%d %d %d %d", &x, &y, &z, &m);

    if (m >= x + y + z) {
        printf("He can buy all 3 books.\n");
    }
    else if (m >= x + y || m >= y + z || m >= z + x) {
        printf("He can buy only 2 books in below order.\n");
        if (m >= x + y) {
            printf("1. Computer Programming\n2.Gonit Korbo Joy\n");
        }
        if (m >= y + z) {
            printf("\n1. Gonit Korbo Joy\n2. Programming er Aschorjo Jogot\n");
        }
        if (m >= z + x) {
            printf("\n1. Computer Programming\n2. Programming er Aschorjo Jogot\n");
        }
    }
    else if (m >= x || m >= y || m >= z) {
        printf("He can buy only one book from below list.\n");
        if (m >= x) {
            printf("Computer Programming\n");
        }
        if (m >= y) {
            printf("Gonit Korbo Joy\n");
        }
        if (m >= z) {
            printf("Programming er Aschorjo Jogot\n");
        }
    }

    return 0;
}