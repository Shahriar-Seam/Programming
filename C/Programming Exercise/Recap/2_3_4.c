#include <stdio.h>

int main()
{
    double goru, chagol;

    printf("Enter gorur dam and chagol er average dam: ");
    scanf("%lf %lf", &goru, &chagol);

    chagol *= 5;

    if (goru > chagol) {
        printf("Thoksen.\n");
    }

    else if (goru < chagol) {
        printf("Jitsen\n");
    }

    else {
        printf("Draw.\n");
    }

    return 0;
}