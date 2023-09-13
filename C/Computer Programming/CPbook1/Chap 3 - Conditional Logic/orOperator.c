#include <stdio.h>

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n >= 1 || n <= 10) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
    // Broken condition. -_- It will always output yes.

    return 0;
}