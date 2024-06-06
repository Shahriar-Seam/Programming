#include <stdio.h>

int main()
{
    int n1, n2, n3, n4, n5;

    printf("Enter your family members age: ");
    scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);

    printf("Discount for age %d -> %d\n", n1, n1 < 12 || n1 > 72);
    printf("Discount for age %d -> %d\n", n2, n2 < 12 || n2 > 72);
    printf("Discount for age %d -> %d\n", n3, n3 < 12 || n3 > 72);
    printf("Discount for age %d -> %d\n", n4, n4 < 12 || n4 > 72);
    printf("Discount for age %d -> %d\n", n5, n5 < 12 || n5 > 72);
}