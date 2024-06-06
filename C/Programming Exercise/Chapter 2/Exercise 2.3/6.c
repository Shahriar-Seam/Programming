#include <stdio.h>

int main()
{
    int taka, achar;

    scanf("%d %d", &taka, &achar);

    if (taka > 10 && !achar) {
        printf("Ice cream\n");
    }
    else if (taka > 10 && achar) {
        printf("Achar\n");
    }
    else {
        printf("Bechara gorib. Kisui khaite parbe na.\n");
    }

    return 0;
}