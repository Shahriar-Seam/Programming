#include <stdio.h>

int main()
{
    int alam, karim, cow1, cow2, cow3;

    printf("Enter prices of Alams cows: \n");
    scanf("%d %d %d", &cow1, &cow2, &cow3);
    alam = cow1 + cow2 + cow3;

    printf("\nEnter prices of Karims cows: \n");
    scanf("%d %d %d", &cow1, &cow2, &cow3);
    karim = cow1 + cow2 + cow3;

    if (alam > karim) {
        printf("\nAlam\n");
    }
    else {
        printf("\nKarim\n");
    }

    return 0;
}