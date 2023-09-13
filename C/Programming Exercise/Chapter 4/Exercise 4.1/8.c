#include <stdio.h>

int main()
{
    int price[10], quantity[10];
    int i, total_product[10], total_value = 0;

    printf("Enter price of the products: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &price[i]);
    }

    printf("Enter quantity of the products: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &quantity[i]);
    }

    for (i = 0; i < 10; i++) {
        total_product[i] = price[i] * quantity[i];
    }

    for (i = 0; i < 10; i++) {
        total_value += total_product[i];
    }

    for (i = 0; i < 10; i++) {
        printf("%d ", total_product[i]);
    }

    printf("\n");

    printf("Total value: %d", total_value);

    return 0;
}